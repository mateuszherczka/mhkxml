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

        const int MALFORMED_XML_ERROR = 1;

        KukaParseExXMLMessage() {

            // we won't need this
            // someBuffer = new char[1024];
        }
        virtual ~KukaParseExXMLMessage() {}

        void printValues() {
            cout << estr << endl;
            cout << xPos << endl;
            cout << yPos << endl;
            cout << zPos << endl;
            cout << cpu << endl;
            cout << fan << endl;
            cout << astate << endl;
            cout << bstate << endl;
            cout << cstate << endl;
            cout << xPos1 << endl;
            cout << yPos1 << endl;
            cout << zPos1 << endl;
            cout << aRot1 << endl;
            cout << bRot1 << endl;
            cout << cRot1 << endl;
            cout << xPos2 << endl;
            cout << yPos2 << endl;
            cout << zPos2 << endl;
            cout << aRot2 << endl;
            cout << bRot2 << endl;
            cout << cRot2 << endl;
            cout << xPos3 << endl;
            cout << yPos3 << endl;
            cout << zPos3 << endl;
            cout << aRot3 << endl;
            cout << bRot3 << endl;
            cout << cRot3 << endl;
        }

        void loadAndParse(const char *filename) {

            doc.LoadFile( filename );
            XMLHandle docHandle( &doc );

            // TODO: rewrite for nullpointer error checking
            externalData = doc.FirstChildElement();

            estr = externalData->FirstChildElement( "TString" )->GetText();

            position = externalData->FirstChildElement( "Position" );

            const char* xposstr = position->FirstChildElement( "XPos" )->GetText();
            xPos= atof(xposstr);


            const char* yposstr = position->FirstChildElement( "YPos" )->GetText();
            yPos= atof(yposstr);


            const char* zposstr = position->FirstChildElement( "ZPos" )->GetText();
            zPos= atof(zposstr);

            temperature = externalData->FirstChildElement( "Temperature" );

            const char* cpustr = temperature->FirstChildElement( "Cpu" )->GetText();
            cpu = atof(cpustr);

            const char* fanstr = temperature->FirstChildElement( "Fan" )->GetText();
            fan = atof(fanstr);

            ints = externalData->FirstChildElement( "Ints" );

            // we can use shorter code but harder to check for nullpointer
            astate = atof(ints->FirstChildElement( "AState" )->GetText());

            bstate = atof(ints->FirstChildElement( "BState" )->GetText());

            boolean = externalData->FirstChildElement( "Boolean" );

            cstate = atof(boolean->FirstChildElement( "CState" )->GetText());

            // use handle for error checking
            // XMLHandle docHandle( &doc );

            xframe1 = docHandle.FirstChildElement( "ExternalData" ).
                        FirstChildElement( "Frames" ).
                        FirstChildElement("XFrame").
                        ToElement();

            if ( xframe1 ) {    // check for nulpointer

                int xmlerr = 0;

                xmlerr += xframe1->QueryDoubleAttribute( "XPos",&xPos1 );    // errorcode 0 if ok

                xmlerr += xframe1->QueryDoubleAttribute( "YPos",&yPos1 );

                xmlerr += xframe1->QueryDoubleAttribute( "ZPos",&zPos1 );

                xmlerr += xframe1->QueryDoubleAttribute( "ARot",&aRot1 );    // errorcode 0 if ok

                xmlerr += xframe1->QueryDoubleAttribute( "BRot",&bRot1 );

                xmlerr += xframe1->QueryDoubleAttribute( "CRot",&cRot1 );

                if (xmlerr != 0) { malformedXMLError("XFrame 1 Attributes"); }
            }
            else {  // something wrong with xml
                malformedXMLError("XFrame 1");
            }

            xframe2 = docHandle.FirstChildElement( "ExternalData" ).
                        FirstChildElement( "Frames" ).
                        NextSiblingElement().
                        FirstChildElement("XFrame").
                        ToElement();

            if ( xframe2 ) {    // check for nullpointer

                int xmlerr = 0;

                xmlerr += xframe2->QueryDoubleAttribute( "XPos",&xPos2 );    // errorcode 0 if ok

                xmlerr += xframe2->QueryDoubleAttribute( "YPos",&yPos2 );

                xmlerr += xframe2->QueryDoubleAttribute( "ZPos",&zPos2 );

                xmlerr += xframe2->QueryDoubleAttribute( "ARot",&aRot2 );    // errorcode 0 if ok

                xmlerr += xframe2->QueryDoubleAttribute( "BRot",&bRot2 );

                xmlerr += xframe2->QueryDoubleAttribute( "CRot",&cRot2 );

                if (xmlerr != 0) { malformedXMLError("XFrame 2 Attributes"); }
            }
            else {  // something wrong with xml
                malformedXMLError("XFrame 2");
            }

            xframe3 = docHandle.FirstChildElement( "ExternalData" ).
                        FirstChildElement( "Frames" ).
                        NextSiblingElement().
                        NextSiblingElement().
                        FirstChildElement("XFrame").
                        ToElement();

            if ( xframe3 ) {    // check for nullpointer

                int xmlerr = 0;

                xmlerr += xframe3->QueryDoubleAttribute( "XPos",&xPos3 );    // errorcode 0 if ok

                xmlerr += xframe3->QueryDoubleAttribute( "YPos",&yPos3 );

                xmlerr += xframe3->QueryDoubleAttribute( "ZPos",&zPos3 );

                xmlerr += xframe3->QueryDoubleAttribute( "ARot",&aRot3 );    // errorcode 0 if ok

                xmlerr += xframe3->QueryDoubleAttribute( "BRot",&bRot3 );

                xmlerr += xframe3->QueryDoubleAttribute( "CRot",&cRot3 );

                if (xmlerr != 0) { malformedXMLError("XFrame 3 Attributes"); }
            }
            else {  // something wrong with xml
                malformedXMLError("XFrame 3");
            }

        }

    protected:
    private:

        //const char *someBuffer;

        int error_state = 0;

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

        XMLElement *xframe2;
        double xPos2;
        double yPos2;
        double zPos2;
        double aRot2;
        double bRot2;
        double cRot2;

        XMLElement *xframe3;
        double xPos3;
        double yPos3;
        double zPos3;
        double aRot3;
        double bRot3;
        double cRot3;

        void malformedXMLError(const char *e) {
            cout << "XML malformed at " << e << " !" << endl;
            error_state = MALFORMED_XML_ERROR;
        }


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
