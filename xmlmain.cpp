// reading a text file
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <boost/tokenizer.hpp>
#include <tinyxml2.h>
//#include <boost/lexical_cast.hpp>

//#include <KukaExXMLMessage.hpp>
//#include <KukaParseExXMLMessage.hpp>
//#include <KukaBuildXMLFrame.hpp>
//#include <KukaParseXMLFrame.hpp>
#include <KukaBuildXMLExample.hpp>
#include <KukaParseXMLExample.hpp>

//using namespace std;
//using namespace boost;
//using namespace tinyxml2;
using boost::lexical_cast;
using boost::bad_lexical_cast;

/*
const char *testframe =
"<Rob> \r\n\
<Frame XPos=\"1\" YPos=\"2\" ZPos=\"3\" ARot=\"4\" BRot=\"5\" CRot=\"6\"/> \r\n\
</Rob> \r\n\
\r\n";

*/

/*
    Gets a pointer to buffer inside streambuf.
    */
    const char * streambufToPtr(boost::asio::streambuf &message) {
        const char* bufPtr=boost::asio::buffer_cast<const char*>(message.data());
        return bufPtr;
    }



/*
void write_app_settings_doc( )
{
    XMLDocument doc;

    //TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );     // <?xml version="1.0" ?>
    //doc.LinkEndChild( decl );
    XMLDeclaration *decl = doc.NewDeclaration("1.0");
    doc.InsertEndChild(decl);


    //TiXmlElement * root = new TiXmlElement( "MyApp" );                  // <MyApp>
    //doc.LinkEndChild( root );
    XMLElement *root = doc.NewElement("MyApp");
    doc.InsertEndChild(root);


    //TiXmlComment * comment = new TiXmlComment();
    //comment->SetValue(" Settings for MyApp " );
    //root->LinkEndChild( comment );
    XMLComment *comment = doc.NewComment("Settings for MyApp");
    root->InsertEndChild(comment);

    //TiXmlElement * msgs = new TiXmlElement( "Messages" );
    //root->LinkEndChild( msgs );
    XMLElement *msgs = doc.NewElement("Messages");
    root->InsertEndChild(msgs);

    //TiXmlElement* msg; // pointer is reused
    XMLElement *msg;

//    msg = new TiXmlElement( "Welcome" );
//    msg->LinkEndChild( new TiXmlText( "Welcome to MyApp" ));
//    msgs->LinkEndChild( msg );

    msg = doc.NewElement("Welcome");
    msg->InsertEndChild(doc.NewText("Welcome to MyApp"));
    msgs->InsertEndChild(msg);

//    msg = new TiXmlElement( "Farewell" );
//    msg->LinkEndChild( new TiXmlText( "Thank you for using MyApp" ));
//    msgs->LinkEndChild( msg );

    msg = doc.NewElement("Farewell");
    msg->InsertEndChild(doc.NewText("Thank you for using MyApp"));
    msgs->InsertEndChild(msg);

//    TiXmlElement * windows = new TiXmlElement( "Windows" );
//    root->LinkEndChild( windows );

    XMLElement *windows = doc.NewElement("Windows");
    root->InsertEndChild(windows);

//    TiXmlElement * window;
//    window = new TiXmlElement( "Window" );
//    windows->LinkEndChild( window );

    XMLElement *window;
    window = doc.NewElement("Window");
    windows->InsertEndChild(window);

    // ok
    window->SetAttribute("name", "MainFrame");
    window->SetAttribute("x", 5);
    window->SetAttribute("y", 15);
    window->SetAttribute("w", 400);
    window->SetAttribute("h", 250);


//    TiXmlElement * cxn = new TiXmlElement( "Connection" );
//    root->LinkEndChild( cxn );
//    cxn->SetAttribute("ip", "192.168.0.1");
//    cxn->SetDoubleAttribute("timeout", 123.456); // floating point attrib

    XMLElement *cxn = doc.NewElement("Connection");
    root->InsertEndChild(cxn);
    cxn->SetAttribute("ip", "192.168.0.1");
    cxn->SetAttribute("timeout", 123.456);

//    dump_to_stdout( &doc );
    doc.SaveFile( "appsettings.xml" );
}

*/
/*
void tokenizeExample() {
    string line;
    ifstream myfile ("example.txt");

    char_separator<char> my_separator(" ");


    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            tokenizer<char_separator<char>> my_tokens(line, my_separator);

            cout << "The line: " << line << endl;

            for (const auto &token : my_tokens) {
                cout << token << endl;
            }


        }
        myfile.close();
    }

    else cout << "Unable to open file";

}

*/
int main () {

        boost::asio::streambuf message;
        //KukaBuildXMLFrame kukaFrame;
        KukaBuildXMLExample kukaExample;

        //kukaFrame.build(message,1,2,3,4,5,6);
        kukaExample.build(message);

        cout << "Built:" << endl;
        cout << streambufToPtr(message);


        //KukaParseXMLFrame kukaParseFrame;
        KukaParseXMLExample kukaParseExample;

        cout << "Parsing from streambuf." << endl;

        //kukaParseFrame.parse(message);
        //kukaParseFrame.printValues();
        kukaParseExample.parse(message);
        kukaParseExample.printValues();

    return 0;
}


/*
#include "tinyxml2.h"

using namespace tinyxml2;

int main(int argc, char* argv[])
{
   tinyxml2::XMLDocument doc;
   tinyxml2::XMLElement* versionNode = doc.NewElement("Version");
   tinyxml2::XMLText* versionText = doc.NewText("1.0.0");

   versionNode->InsertEndChild(versionText);
   doc.InsertEndChild(versionNode);

   XMLPrinter printer;
   doc.Print();

   return 0;
}
*/

/*
<?xml version="1.0" ?>
<MyApp>
    <!-- Settings for MyApp -->
    <Messages>
        <Welcome>Welcome to MyApp</Welcome>
        <Farewell>Thank you for using MyApp</Farewell>
    </Messages>
    <Windows>
        <Window name="MainFrame" x="5" y="15" w="400" h="250" />
    </Windows>
    <Connection ip="192.168.0.1" timeout="123.456000" />
</MyApp>
*/


// much better way to access entire message
//        boost::asio::streambuf::const_buffers_type bufs = message.data();
//        std::string astr(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + message.size());
//        cout << astr.c_str();
//        cout << astr;



//        std::istream is(&message);
//        std::string s;
//        while (std::getline(is, s) && s != "\r\n") {
//            std::cout << s << "\n";
//        }

//        std::istream is2(&message);
//        std::string s2;
//
//        is2 >> s2;
//
//        std::cout << s2;

/*
        cout << "Printing line by line." << endl;
        std::istream is(&message);
        std::string s;
        while (std::getline(is, s) && s != "\r\n") {
            std::cout << s << "\n";
        }
        */

        /*
        cout << "Trying ostringstream." << endl;
        std::ostringstream ss;
        ss << &message;
        std::string message_str = ss.str();
        cout << message_str;
        */

        //const char *message_str = streambufToString(message).c_str();

        //cout << message_str;

        /*
        cout << "Parsing from quoted string." << endl;
        kukaParseFrame.parse(testframe);
        kukaParseFrame.printValues();
        */
        /*
        cout << "Parsing from streambuf externally.";
        XMLDocument doc;
        doc.Parse(message_str.c_str());
        //XMLHandle docHandle( &doc );

        XMLError xml_error_state = doc.ErrorID();
        if ( xml_error_state != 0 ) {
            //XMLError("Buffer could't be parsed");
            cout << "ErrorID: " << xml_error_state << endl;
            return false;
        }

        */

        //    tokenizeExample();
//    write_app_settings_doc();
//    char *created_filename = "kuka_ex_xml.xml";
//    KukaExXMLMessage kexml_msg;

    //kexml_msg.toFile(created_filename);

    //char *external_filename = "ExternalData.xml";

    //kexml_msg.printAllCharsFromFile(created_filename);
    //kexml_msg.printAllCharsFromFile(external_filename);

    //kexml_msg.printAllAsciiFromTwoFiles(external_filename,created_filename);    // kuka file is A

//    kexml_msg.printSpfXml();

//    KukaParseExXMLMessage kpex;
//    kpex.loadAndParse(external_filename);
//    kpex.printValues();

        //cout << testframe;

/*
Copies (?) streambuf to a string and returns it.
*/

/*
std::string streambufToString(boost::asio::streambuf &message) {
    boost::asio::streambuf::const_buffers_type bufs = message.data();
    std::string astr(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + message.size());
    return astr;
}

const char * streambufToPtr(boost::asio::streambuf &message) {
    boost::asio::streambuf::const_buffers_type bufs = message.data();
    std::string astr(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + message.size());
    return astr.c_str();
}
*/
/*
// alternative using stringstream
const char * streambufToPtr(boost::asio::streambuf &message) {
    std::ostringstream ss;
    ss << &message;
    std::string astr = ss.str();
    return astr.c_str();
}
*/
