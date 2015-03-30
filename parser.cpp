#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <list>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <string>
#include <stdexcept>
using namespace xercesc;
using namespace std;
enum {
   ERROR_ARGS = 1, 
   ERROR_XERCES_INIT,
   ERROR_PARSE,
   ERROR_EMPTY_DOCUMENT
};

class GetConfig
{
public:
   GetConfig();
  ~GetConfig();
   void readConfigFile(std::string&,std::string&) throw(std::runtime_error);
private:
   xercesc::XercesDOMParser *m_ConfigFileParser;
   xercesc::XercesDOMParser *tempparser;
   // Internal class use only. Hold Xerces data in UTF-16 SMLCh type.
   XMLCh* TAG_Class;
   XMLCh* ATTR_Branch;
   XMLCh* ATTR_Year;
   
   XMLCh* TAG_Student;
   XMLCh* ATTR_Regno;
   
   XMLCh* TAG_Subject;
   XMLCh* ATTR_Code;
   
   XMLCh* TAG_Question;
   XMLCh* ATTR_Que_no;
   
   XMLCh* TAG_Tick;
   XMLCh* TAG_Cross;
   XMLCh* TAG_Quesmark;
   XMLCh* TAG_Circle;
   XMLCh* TAG_Hightext;
   XMLCh* TAG_Comment;
   XMLCh* TAG_Marks;
   XMLCh* TAG_Fullmarks;
   XMLCh* TAG_Checkedby;
   };

GetConfig::GetConfig()
{
   try
   {
      XMLPlatformUtils::Initialize();  // Initialize Xerces infrastructure
   }
   catch( XMLException& e )
   {
      char* message = XMLString::transcode( e.getMessage() );
      cerr << "XML toolkit initialization error: " << message << endl;
      XMLString::release( &message );
      // throw exception here to return ERROR_XERCES_INIT
   }

   // Tags and attributes used in XML file.
   // Can't call transcode till after Xerces Initialize()
   TAG_Class = XMLString::transcode("class");
   ATTR_Branch = XMLString::transcode("branch");
   ATTR_Year = XMLString::transcode("year");
   
   TAG_Student = XMLString::transcode("student");
   ATTR_Regno = XMLString::transcode("regno");
   
   TAG_Subject = XMLString::transcode("subject");
   ATTR_Code = XMLString::transcode("code");
   
   TAG_Question = XMLString::transcode("question");
   ATTR_Que_no = XMLString::transcode("ques_no");
   
   TAG_Tick = XMLString::transcode("tick");
   TAG_Cross = XMLString::transcode("cross");
   TAG_Quesmark = XMLString::transcode("ques_mark");
   TAG_Circle = XMLString::transcode("circle");
   TAG_Hightext = XMLString::transcode("high_text");
   TAG_Marks = XMLString::transcode("marks");
   TAG_Comment = XMLString::transcode("comment");
   TAG_Fullmarks = XMLString::transcode("full_marks");
   TAG_Checkedby = XMLString::transcode("checked_by");

   m_ConfigFileParser = new XercesDOMParser;
   tempparser = new XercesDOMParser;
}

/**
 *  Class destructor frees memory used to hold the XML tag and 
 *  attribute definitions. It als terminates use of the xerces-C
 *  framework.
 */

GetConfig::~GetConfig()
{
   // Free memory
   delete tempparser;
   delete m_ConfigFileParser;
   try
   {
      XMLString::release( &TAG_Class );

      XMLString::release( &TAG_Student );
      XMLString::release( &TAG_Subject );
      XMLString::release( &TAG_Question );
      XMLString::release( &TAG_Tick );
      XMLString::release( &TAG_Cross );
      XMLString::release( &TAG_Quesmark );
      XMLString::release( &TAG_Hightext );
      XMLString::release( &TAG_Circle );
      XMLString::release( &TAG_Marks );
      XMLString::release( &TAG_Comment );
      XMLString::release( &TAG_Fullmarks );
      XMLString::release( &TAG_Checkedby );
   }
   catch( ... )
   {
      cerr << "Unknown exception encountered in TagNamesdtor" << endl;
   }

   // Terminate Xerces

   try
   {
      XMLPlatformUtils::Terminate();  // Terminate after release of memory
   }
   catch( xercesc::XMLException& e )
   {
      char* message = xercesc::XMLString::transcode( e.getMessage() );

      cerr << "XML ttolkit teardown error: " << message << endl;
      XMLString::release( &message );
   }
}

/**
 *  This function:
 *  - Tests the access and availability of the XML configuration file.
 *  - Configures the xerces-c DOM parser.
 *  - Reads and extracts the pertinent information from the XML config file.
 *
 *  @param in configFile The text string name of the HLA configuration file.
 */

void GetConfig::readConfigFile(string& configFile,string& temp)
        throw( std::runtime_error )
{
   // Test to see if the file is ok.

   struct stat fileStatus;

   int iretStat = stat(configFile.c_str(), &fileStatus);
   if( iretStat == ENOENT )
      throw ( std::runtime_error("Path file_name does not exist, or path is an empty string.") );
   else if( iretStat == ENOTDIR )
      throw ( std::runtime_error("A component of the path is not a directory."));
   else if( iretStat == ELOOP )
      throw ( std::runtime_error("Too many symbolic links encountered while traversing the path."));
   else if( iretStat == EACCES )
      throw ( std::runtime_error("Permission denied."));
   else if( iretStat == ENAMETOOLONG )
      throw ( std::runtime_error("File can not be read\n"));

   struct stat status;
   int st=stat(temp.c_str(),&status);
   if( st == ENOENT )
      throw ( std::runtime_error("Path file_name does not exist, or path is an empty string.") );
   else if( st == ENOTDIR )
      throw ( std::runtime_error("A component of the path is not a directory."));
   else if( st == ELOOP )
      throw ( std::runtime_error("Too many symbolic links encountered while traversing the path."));
   else if( st == EACCES )
      throw ( std::runtime_error("Permission denied."));
   else if( st == ENAMETOOLONG )
      throw ( std::runtime_error("File can not be read\n"));
   
   
   // Configure DOM parser.

   m_ConfigFileParser->setValidationScheme( XercesDOMParser::Val_Never );
   m_ConfigFileParser->setDoNamespaces( false );
   m_ConfigFileParser->setDoSchema( false );
   m_ConfigFileParser->setLoadExternalDTD( false );
    tempparser->setValidationScheme( XercesDOMParser::Val_Never );
   tempparser->setDoNamespaces( false );
   tempparser->setDoSchema( false );
   tempparser->setLoadExternalDTD( false );

   try
   {
      m_ConfigFileParser->parse( configFile.c_str() );
      tempparser->parse(temp.c_str());

      // no need to free this pointer - owned by the parent parser object
      DOMDocument* xmlDoc = m_ConfigFileParser->getDocument();
      DOMDocument* tempdoc= tempparser->getDocument();

      // Get the top-level element: NAme is "root". No attributes for "root"
      
      DOMElement* elementRoot = xmlDoc->getDocumentElement();
      DOMElement* root=tempdoc->getDocumentElement();
      if(!elementRoot)
      {
            		
      //if( !elementRoot ) throw(std::runtime_error( "empty XML document" ));

      // Parse XML file for tags of interest: "ApplicationSettings"
      // Look one level nested within "root". (child of root)

      DOMNodeList*      stu_children = elementRoot->getChildNodes();
      DOMNodeList*      stu_tempchildren=root->getChildNodes();
      XMLSize_t nodeCount = stu_children->getLength();
      XMLSize_t tempnodecount=stu_tempchildren->getLength();
      
      // For all nodes, children of "root" in the XML tree.
	DOMNode* currentNode;
	DOMNode* tempnode;
	XMLSize_t xx;
      for(  xx = 0; xx < tempnodecount; ++xx )
      {
      	 currentNode = stu_children->item(xx);
      	for(unsigned int yy=0;yy<nodeCount;yy++)
      	{
      	 tempnode=stu_tempchildren->item(yy);
         
         if( currentNode->getNodeType() &&  // true is not NULL
             currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) // is element 
         {
            // Found node which is an Element. Re-cast node as element
            DOMElement* currentElement= dynamic_cast< xercesc::DOMElement* >( currentNode );
            DOMElement* currenttempelement= dynamic_cast< xercesc::DOMElement* >( tempnode );
            if( XMLString::equals(currentElement->getTagName(), currenttempelement->getTagName()))
            {
 		if(XMLString::equals(currentElement->getAttribute(ATTR_Regno),currenttempelement->getAttribute(ATTR_Regno)))
 		 {
 		 	DOMNodeList* sub_children=currentElement->getChildNodes();
 		 	DOMNodeList* sub_tempchildren=currenttempelement->getChildNodes();
 		 	XMLSize_t sub_nodecount=sub_children->getLength();
 		 	XMLSize_t sub_tempnodecount=sub_tempchildren->getLength();
 		 	  for(unsigned int y=0;y<sub_tempnodecount;y++)
 		 	  {
 		 	  	DOMNode* sub_tempcurrentnode=sub_tempchildren->item(y);
 		 	  	for(unsigned int x=0;x<sub_nodecount;x++)
 		 	  	{
 		 	  		DOMNode* sub_currentnode=sub_children->item(x);
 		 	  		if(sub_tempcurrentnode->getNodeType()&&sub_currentnode->getNodeType()&&sub_tempcurrentnode->getNodeType()==DOMNode::ELEMENT_NODE&&sub_currentnode->getNodeType()==DOMNode::ELEMENT_NODE)
 		 	  		{
 		 	  		  DOMElement* sub_tempelement=dynamic_cast< xercesc::DOMElement*>(sub_tempcurrentnode);
 		 	  		  DOMElement* sub_element=dynamic_cast<xercesc::DOMElement*>(sub_currentnode);
 if(XMLString::equals(sub_tempelement->getAttribute(ATTR_Code),sub_element->getAttribute(ATTR_Code)))
 		 	  		  {
 		 	  		  	DOMNodeList* que_tempchildren=sub_tempelement->getChildNodes();
 		 	  		  	//que_children=sub_element->getChildNodes();
 		 	  		  	XMLSize_t que_tempnodecount=stu_tempchildren->getLength();
 		 	  		  	//XMLSize_t que_nodecount=stu_children->getLength();
 		 	  		  	for(unsigned int que_no=0;que_no<que_tempnodecount;que_no++)
 		 	  		  	{
 		 	  		  		DOMNode* que_tempcurrentnode=que_tempchildren->item(que_no);
 		 	  		  	        sub_element->appendChild(dynamic_cast<xercesc::DOMElement*> (que_tempcurrentnode));
 		 	  		  	}
 		 	  		  }
 		 	  		  sub_element->appendChild(sub_tempelement);
 		 	  		  }
 		 	        }
 		 	  }
 		 }
 		 currentElement->appendChild(currenttempelement);
 		 }
 		 
 	
            }
         }
      }
   }
   }
   catch( xercesc::XMLException& e )
   {
	system("cp temp configfile");
   }
}
int main()
{
   string configFile="./sample.xml"; // stat file. Get ambigious segfault otherwise.
   string temp="./temp.xml";
   GetConfig appConfig;
   appConfig.readConfigFile(configFile,temp);
   return 0;
}


