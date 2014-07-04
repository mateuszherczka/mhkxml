#ifndef KUKAPARSEEXXMLMESSAGE_H
#define KUKAPARSEEXXMLMESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

#include <tinyxml2.h>

// TODO: separate parsing for error checking!

using namespace std;
using namespace tinyxml2;

class KukaParseExXMLMessage
{
    public:

        KukaParseExXMLMessage() {
            someBuffer = new char[1024];
        }
        virtual ~KukaParseExXMLMessage() {}

        void loadAndParse(const char *filename) {

            doc.LoadFile( filename );

            // TODO: rewrite for nullpointer error checking
            externalData = doc.FirstChildElement();

            estr = externalData->FirstChildElement( "TString" )->GetText();
            cout << estr << endl;

            position = externalData->FirstChildElement( "Position" );

            const char* xposstr = position->FirstChildElement( "XPos" )->GetText();
            xPos= atof(xposstr);
            cout << xPos << endl;

            const char* yposstr = position->FirstChildElement( "YPos" )->GetText();
            yPos= atof(yposstr);
            cout << yPos << endl;

            const char* zposstr = position->FirstChildElement( "ZPos" )->GetText();
            zPos= atof(zposstr);
            cout << zPos << endl;

            temperature = externalData->FirstChildElement( "Temperature" );

            const char* cpustr = temperature->FirstChildElement( "Cpu" )->GetText();
            cpu = atof(cpustr);
            cout << cpu << endl;

            const char* fanstr = temperature->FirstChildElement( "Fan" )->GetText();
            fan = atof(fanstr);
            cout << fan << endl;

            ints = externalData->FirstChildElement( "Ints" );

            // we can use shorter code but harder to check for nullpointer
            astate = atof(ints->FirstChildElement( "AState" )->GetText());
            cout << astate << endl;

            bstate = atof(ints->FirstChildElement( "BState" )->GetText());
            cout << bstate << endl;

            boolean = externalData->FirstChildElement( "Boolean" );

            cstate = atof(boolean->FirstChildElement( "CState" )->GetText());
            cout << cstate << endl;

//            frames1 = externalData->FirstChildElement( "Frames" );
//            frames2 = frames1->NextSiblingElement();
//            frames3 = frames2->NextSiblingElement();

            // use handle for error checking
            XMLHandle docHandle( &doc );
            xframe1 = docHandle.FirstChildElement( "ExternalData" ).FirstChildElement( "Frames" ).FirstChildElement("XFrame").ToElement();

            if ( xframe1 ) {    // check for nulpointer

                int xmlerr;

                xmlerr = xframe1->QueryDoubleAttribute( "XPos",&xPos1 );    // errorcode 0 if ok
                cout << xPos1 << " " << "errorcode: " << xmlerr << endl;

                xmlerr = xframe1->QueryDoubleAttribute( "YPos",&yPos1 );
                cout << yPos1 << " " << "errorcode: " << xmlerr << endl;

                xmlerr = xframe1->QueryDoubleAttribute( "ZPos",&zPos1 );
                cout << zPos1 << " " << "errorcode: " << xmlerr << endl;

                xmlerr = xframe1->QueryDoubleAttribute( "XPos",&xPos1 );    // errorcode 0 if ok
                cout << xPos1 << " " << "errorcode: " << xmlerr << endl;

                xmlerr = xframe1->QueryDoubleAttribute( "YPos",&yPos1 );
                cout << yPos1 << " " << "errorcode: " << xmlerr << endl;

                xmlerr = xframe1->QueryDoubleAttribute( "ZPos",&zPos1 );
                cout << zPos1 << " " << "errorcode: " << xmlerr << endl;
            }
            else {  // something wrong with xml
                cout << "XML malformed!" << endl;
            }

        }

    protected:
    private:

        const char *someBuffer;

        XMLDocument doc;
        XMLElement *externalData;
        const char *estr;
        XMLElement *position;
        double xPos;
        double yPos;
        double zPos;
        XMLElement *temperature;
        double cpu;
        double fan;
        XMLElement *ints;
        int astate;
        int bstate;
        XMLElement *boolean;
        int cstate;

        XMLElement *xframe1;
        double xPos1;
        double yPos1;
        double zPos1;
        double aRot1;
        double bRot1;
        double cRot1;

//    XML
//    XMLElement *position;


};

#endif // KUKAPARSEEXXMLMESSAGE_H

/* ------ Example 2: Lookup information. ---- */
/*
{
    XMLDocument doc;
    doc.LoadFile( "dream.xml" );

    // Structure of the XML file:
    // - Element "PLAY"      the root Element, which is the
    //                       FirstChildElement of the Document
    // - - Element "TITLE"   child of the root PLAY Element
    // - - - Text            child of the TITLE Element

    // Navigate to the title, using the convenience function,
    // with a dangerous lack of error checking.
    const char* title = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" )->GetText();
    printf( "Name of play (1): %s\n", title );

    // Text is just another Node to TinyXML-2. The more
    // general way to get to the XMLText:
    XMLText* textNode = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" )->FirstChild()->ToText();
    title = textNode->Value();
    printf( "Name of play (2): %s\n", title );
}
*/
