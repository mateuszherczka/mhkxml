#ifndef KUKAPARSEXMLFRAME_H
#define KUKAPARSEXMLFRAME_H


class KukaParseXMLFrame
{
    public:
        const int MALFORMED_XML_ERROR = 1;

        KukaParseXMLFrame() {}
        virtual ~KukaParseXMLFrame() {

            // TODO: destructor
        }

        bool parse(const char* buffer) {

            doc.Parse(buffer);
            xml_error_state = doc.ErrorID();
            if ( xml_error_state != 0 ) {
                XMLError("Buffer could't be parsed");
                return false;
            }


            frame = docHandle.FirstChildElement( "Rob" ).
                        FirstChildElement( "Frame" ).
                        ToElement();

            if ( frame ) {    // check for nulpointer

                int xmlerr = 0;

                xmlerr += frame->QueryDoubleAttribute( "XPos",&xPos );    // errorcode 0 if ok

                xmlerr += frame->QueryDoubleAttribute( "YPos",&yPos );

                xmlerr += frame->QueryDoubleAttribute( "ZPos",&zPos );

                xmlerr += frame->QueryDoubleAttribute( "ARot",&aRot );    // errorcode 0 if ok

                xmlerr += frame->QueryDoubleAttribute( "BRot",&bRot );

                xmlerr += frame->QueryDoubleAttribute( "CRot",&cRot );

                if (xmlerr != 0) { XMLError("Frame Attributes"); }
            }
            else {  // something wrong with xml
                XMLError("Frame");
                return false;
            }
        }

    protected:
    private:

    //int error_state = 0;
    int xml_error_state = 0;
    XMLDocument doc;

    double xPos;
    double yPos;
    double zPos;

    double aRot;
    double bRot;
    double cRot;

    XMLElement *xframe;

    void XMLError(const char *e) {
        cout << "XML malformed at " << e << " !" << endl;
        xml_error_state = MALFORMED_XML_ERROR;
    }

};

#endif // KUKAPARSEXMLFRAME_H
