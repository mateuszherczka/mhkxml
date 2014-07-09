#ifndef KUKABUILDXMLFRAME_H
#define KUKABUILDXMLFRAME_H

#include <boost/asio.hpp>
//#include <boost/system.hpp>

//using boost::asio;
//using std;
//
class KukaBuildXMLFrame
{
    public:
        KukaBuildXMLFrame() {
            //outDataBuffer = new char[BUFFER_SIZE];
        }
        virtual ~KukaBuildXMLFrame() {
            // TODO: destructor
        }

        /*
        No Tabs, as clean as possible;
        Pass in a buffer. Make sure it's long enough;
        Returns buffer length.
        */
        /*
        int build( char *buffer,
                    const double xpos,
                    const double ypos,
                    const double zpos,
                    const double arot,
                    const double brot,
                    const double crot ) {

            return sprintf(buffer,FrameXMLFormat,

                xpos,ypos,zpos,arot,brot,crot

            );
        }
        */

        /*
        Fills a boost streambuf.
        */
        void build( boost::asio::streambuf &message,
                    const double xpos,
                    const double ypos,
                    const double zpos,
                    const double arot,
                    const double brot,
                    const double crot ) {

            std::ostream to_message_stream(&message);

            to_message_stream   << "<Rob>\r\n";
            to_message_stream   << "<Frame XPos=\"" << xpos << "\" "
                                << "YPos=\"" << ypos << "\" "
                                << "ZPos=\"" << zpos << "\" "
                                << "ARot=\"" << arot << "\" "
                                << "BRot=\"" << brot << "\" "
                                << "CRot=\"" << crot << "\"/>\r\n";
            to_message_stream   << "</Rob>\r\n";
            //to_message_stream   << "\r\n";
        }

    protected:
    private:

        const int TAB = 9;
        const int LF = 10;
        const int CR = 13;
        const int BR = LF;

        //const int BUFFER_SIZE = 10240;

        //char *outDataBuffer;
        int outDataBufferLength = 0;

        const char* FrameXMLFormat =
"<Rob> \n\
<Frame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" /> \n\
</Rob> \n";

};

#endif // KUKABUILDXMLFRAME_H
