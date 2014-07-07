#ifndef KUKABUILDXMLFRAME_H
#define KUKABUILDXMLFRAME_H


class KukaBuildXMLFrame
{
    public:
        KukaBuildXMLFrame() {
            outDataBuffer = new char[BUFFER_SIZE];
        }
        virtual ~KukaBuildXMLFrame() {
            // TODO: destructor
        }

        /*
        No Tabs, as clean as possible;
        */
        void build( const char *buffer,
                    const double xpos,
                    const double ypos,
                    const double zpos,
                    const double arot,
                    const double brot,
                    const double crot ) {

            outDataBufferLength = sprintf(buffer,FrameXMLFormat,

                xpos,ypos,zpos,arot,brot,crot,

            );
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
</Rob> \n\

};

#endif // KUKABUILDXMLFRAME_H
