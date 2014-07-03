#include <iostream>
#include <fstream>
#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

/*

<ExternalData>
    <TString>EKX message example!</TString>
    <Position>
        <XPos>1523.232</XPos>
        <YPos>494.2343</YPos>
        <ZPos>14.4</ZPos>
    </Position>
    <Temperature>
        <Cpu>35.09787</Cpu>
        <Fan>40.75869</Fan>
    </Temperature>
    <Ints>
        <AState>23456</AState>
        <BState>64</BState>
    </Ints>
    <Boolean>
        <CState>0</CState>
    </Boolean>
    <Frames>
        <XFrame XPos="1.6" YPos="2.5" ZPos="3.4" ARot="4.3" BRot="5.2" CRot="6.1" />
    </Frames>
    <Frames>
        <XFrame XPos="13.1" YPos="24.5" ZPos="837.54" ARot="142.3" BRot="65.2" CRot="56.94" />
    </Frames>
    <Frames>
        <XFrame XPos="764.6" YPos="134.5" ZPos="36.54" ARot="24.3" BRot="36.2" CRot="5" />
    </Frames>
</ExternalData>

*/

/*
XMLElement* xedatensatz = doc.NewElement("Datensatz");
XMLElement* xejahr = doc.NewElement("Jahr");
XMLElement* xemonat = doc.NewElement("Monat");
datensatzJahr = doc.NewText(m_gd_data->GetCellValue(i,0));
datensatzMonat = doc.NewText(m_gd_data->GetCellValue(i,1));
xejahr->InsertEndChild(datensatzJahr);
xemonat->InsertEndChild(datensatzMonat);
xedatensatz->InsertEndChild(xejahr);
xedatensatz->InsertEndChild(xemonat);
xesql->InsertEndChild(xedatensatz);
*/

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

/*
void write_app_settings_doc( )  
{  
    TiXmlDocument doc;  
    TiXmlElement* msg;
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );     // <?xml version="1.0" ?>
    doc.LinkEndChild( decl );  
    
    TiXmlElement * root = new TiXmlElement( "MyApp" );                  // <MyApp>
    doc.LinkEndChild( root );  
    
    TiXmlComment * comment = new TiXmlComment();
    comment->SetValue(" Settings for MyApp " );  
    root->LinkEndChild( comment );  
    
    TiXmlElement * msgs = new TiXmlElement( "Messages" );  
    root->LinkEndChild( msgs );  
    
    msg = new TiXmlElement( "Welcome" );  
    msg->LinkEndChild( new TiXmlText( "Welcome to MyApp" ));  
    msgs->LinkEndChild( msg );  
    
    msg = new TiXmlElement( "Farewell" );  
    msg->LinkEndChild( new TiXmlText( "Thank you for using MyApp" ));  
    msgs->LinkEndChild( msg );  
    
    TiXmlElement * windows = new TiXmlElement( "Windows" );  
    root->LinkEndChild( windows );  
    
    TiXmlElement * window;
    window = new TiXmlElement( "Window" );  
    windows->LinkEndChild( window );  
    window->SetAttribute("name", "MainFrame");
    window->SetAttribute("x", 5);
    window->SetAttribute("y", 15);
    window->SetAttribute("w", 400);
    window->SetAttribute("h", 250);
    
    TiXmlElement * cxn = new TiXmlElement( "Connection" );  
    root->LinkEndChild( cxn );  
    cxn->SetAttribute("ip", "192.168.0.1");
    cxn->SetDoubleAttribute("timeout", 123.456); // floating point attrib
    
    dump_to_stdout( &doc );
    doc.SaveFile( "appsettings.xml" );  
}
*/
