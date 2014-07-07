#ifndef KUKAPARSEXMLEXAMPLE_H
#define KUKAPARSEXMLEXAMPLE_H

// TODO: finish this
class KukaParseXMLExample
{
    public:
        KukaParseXMLExample() {}
        virtual ~KukaParseXMLExample() {}

        void parse(const char *buffer) {

            doc.Parse( buffer );
            XMLHandle docHandle( &doc );


            // TODO: rewrite for nullpointer error checking
            externalData = doc.FirstChildElement();

            //estr = externalData->FirstChildElement( "TString" )->FirstChild()->Value();

            tstring = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "TString" )
                        .FirstChild()   // this is a text, not an element
                        .ToText();

            if( tstring ) {
                if ( tstring->Value() ) {
                    estr = tstring->Value();
                }
                else {  // something wrong with xml
                    malformedXMLError("TString Value");
                }
            }
            else {  // something wrong with xml
                malformedXMLError("TString");
            }

            //estr = externalData->FirstChildElement( "TString" )->GetText();

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

        const int MALFORMED_XML_ERROR = 666;
        int error_state = 0;

        XMLDocument doc;

        XMLElement *externalData;
        //XMLElement *tstring;
        XMLText *tstring;
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

#endif // KUKAPARSEXMLEXAMPLE_H
