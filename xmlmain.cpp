// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <boost/tokenizer.hpp>
#include <tinyxml2.h>

#include <KukaExXMLMessage.hpp>
#include <KukaParseExXMLMessage.hpp>
#include <KukaBuildXMLFrame.hpp>

using namespace std;
using namespace boost;
using namespace tinyxml2;

/*
Copies (?) streambuf to a string and returns it.
*/
std::string streambufToString(boost::asio::streambuf &message) {
    boost::asio::streambuf::const_buffers_type bufs = message.data();
    std::string astr(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + message.size());
    //return astr.c_str();
    return astr;
}


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
int main () {

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

        boost::asio::streambuf message;
        KukaBuildXMLFrame kukaFrame;

        kukaFrame.build(message,1,2,3,4,5,6);

        cout << streambufToString(message).c_str();

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
