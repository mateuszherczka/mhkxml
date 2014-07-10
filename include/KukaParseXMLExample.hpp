#ifndef KUKAPARSEXMLEXAMPLE_H
#define KUKAPARSEXMLEXAMPLE_H

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <tinyxml2.h>

using namespace tinyxml2;
using std::cout;
using std::endl;

using boost::lexical_cast;
using boost::bad_lexical_cast;

class KukaParseXMLExample
{
    public:
        KukaParseXMLExample() {}
        virtual ~KukaParseXMLExample() {}

        /*
        Pass a boost::streambuf
        */
        bool parse(boost::asio::streambuf &message) {
            return parse(streambufToPtr(message));
        }

        bool parse(const char *buffer) {

            // TODO: Restructure parse code so all checks occur in beginning
            // before any values are changed

            // TODO: catch lexical_cast exception

            doc.Parse( buffer );
            XMLHandle docHandle( &doc );

            XMLText *nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "TString" )
                        .FirstChild()   // this is a text, not an element
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    estr = nodeval->Value();
                }
                else {  // something wrong with xml
                    malformedXMLError("TString Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("TString");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Position" )
                        .FirstChildElement("XPos")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    xPos = boost::lexical_cast<double>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("XPos Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("XPos");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Position" )
                        .FirstChildElement("YPos")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    yPos = boost::lexical_cast<double>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("YPos Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("YPos");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Position" )
                        .FirstChildElement("ZPos")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    zPos = boost::lexical_cast<double>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("ZPos Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("ZPos");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Temperature" )
                        .FirstChildElement("Cpu")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    cpu = boost::lexical_cast<double>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("Cpu Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("Cpu");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Temperature" )
                        .FirstChildElement("Fan")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    fan = boost::lexical_cast<double>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("Fan Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("Fan");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Ints" )
                        .FirstChildElement("AState")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    astate = boost::lexical_cast<int>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("AState Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("AState");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Ints" )
                        .FirstChildElement("BState")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    bstate = boost::lexical_cast<int>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("BState Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("BState");
                return false;
            }

            nodeval = docHandle.FirstChildElement( "ExternalData" )
                        .FirstChildElement( "Boolean" )
                        .FirstChildElement("CState")   // this is a text, not an element
                        .FirstChild()
                        .ToText();

            if( nodeval ) {
                if ( nodeval->Value() ) {
                    cstate = boost::lexical_cast<bool>(nodeval->Value());
                }
                else {  // something wrong with xml
                    malformedXMLError("CState Value");
                    return false;
                }
            }
            else {  // something wrong with xml
                malformedXMLError("BState");
                return false;
            }

            XMLElement *xframe1 = docHandle.FirstChildElement( "ExternalData" ).
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
                return false;
            }

            XMLElement *xframe2 = docHandle.FirstChildElement( "ExternalData" ).
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
                return false;
            }

            XMLElement *xframe3 = docHandle.FirstChildElement( "ExternalData" ).
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
                return false;
            }

            return true;

        }

        void printValues() {
            cout << estr << endl;
            cout << xPos << " "
                    << yPos << " "
                    << zPos << endl;
            cout << cpu << " "
                    << fan << endl;
            cout << astate << " "
                    << bstate << " "
                    << cstate << endl;
            cout << xPos1 << " "
                    << yPos1 << " "
                    << zPos1 << " "
                    << aRot1 << " "
                    << bRot1 << " "
                    << cRot1 << endl;
            cout << xPos2 << " "
                    << yPos2 << " "
                    << zPos2 << " "
                    << aRot2 << " "
                    << bRot2 << " "
                    << cRot2 << endl;
            cout << xPos3 << " "
                    << yPos3 << " "
                    << zPos3 << " "
                    << aRot3 << " "
                    << bRot3 << " "
                    << cRot3 << endl;
        }
    protected:
    private:

        /*
        Gets a pointer to buffer inside streambuf.
        */
        const char * streambufToPtr(boost::asio::streambuf &message) {
            const char* bufPtr=boost::asio::buffer_cast<const char*>(message.data());
            return bufPtr;
        }

        const int MALFORMED_XML_ERROR = 666;
        int error_state = 0;

        XMLDocument doc;

        //XMLElement *externalData;
        //XMLElement *tstring;
        //XMLText *tstring;
        const char *estr;
        //XMLElement *position;
        double xPos;
        double yPos;
        double zPos;
        //XMLElement *temperature;
        double cpu;
        double fan;
        //XMLElement *ints;
        int astate;
        int bstate;
        //XMLElement *boolean;
        bool cstate;

        //XMLElement *xframe1;
        double xPos1;
        double yPos1;
        double zPos1;
        double aRot1;
        double bRot1;
        double cRot1;

        //XMLElement *xframe2;
        double xPos2;
        double yPos2;
        double zPos2;
        double aRot2;
        double bRot2;
        double cRot2;

        //XMLElement *xframe3;
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

//estr = externalData->FirstChildElement( "TString" )->GetText();

//externalData = doc.FirstChildElement();

            //estr = externalData->FirstChildElement( "TString" )->FirstChild()->Value();

//position = externalData->FirstChildElement( "Position" );

            //const char* xposstr = position->FirstChildElement( "XPos" )->GetText();
            //xPos= = boost::lexical_cast<double>(xposstr);
            //atof(xposstr);


            //const char* yposstr = position->FirstChildElement( "YPos" )->GetText();
            //yPos= atof(yposstr);


            //const char* zposstr = position->FirstChildElement( "ZPos" )->GetText();
            //zPos= atof(zposstr);

            //temperature = externalData->FirstChildElement( "Temperature" );

            //const char* cpustr = temperature->FirstChildElement( "Cpu" )->GetText();
            //cpu = atof(cpustr);

            //const char* fanstr = temperature->FirstChildElement( "Fan" )->GetText();
            //fan = atof(fanstr);

            //ints = externalData->FirstChildElement( "Ints" );

            // we can use shorter code but harder to check for nullpointer
            //astate = atof(ints->FirstChildElement( "AState" )->GetText());

            //bstate = atof(ints->FirstChildElement( "BState" )->GetText());

            //boolean = externalData->FirstChildElement( "Boolean" );

            //cstate = atof(boolean->FirstChildElement( "CState" )->GetText());

            // use handle for error checking
            // XMLHandle docHandle( &doc );
