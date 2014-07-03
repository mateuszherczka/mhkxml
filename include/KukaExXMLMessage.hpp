#ifndef KUKAEXXMLMESSAGE_H
#define KUKAEXXMLMESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

/**
    Holds an xml structure similar to
    kuka krlxml demo app.
*/

class KukaExXMLMessage
{
    public:
        KukaExXMLMessage() {}
        virtual ~KukaExXMLMessage() {}

    protected:

    private:

    XMLDocument doc;

    XMLElement  *external_data;

    XMLElement  *t_string;
    XMLText     *t_string_text;

    XMLElement  *position;
    XMLElement  *xpos;
    XMLText     *xpos_text;
    XMLElement  *ypos;
    XMLText     *ypos_text;
    XMLElement  *zpos;
    XMLText     *zpos_text;

    XMLElement  *temperature;
    XMLElement  *cpu;
    XMLElement  *fan;

    XMLElement  *ints;
    XMLElement  *astate;
    XMLElement  *bstate;

    XMLElement  *boolean;
    XMLElement  *cstate;

    XMLElement  *frames_1;
    XMLElement  *xframe_1;

    XMLElement  *frames_2;
    XMLElement  *xframe_2;

    XMLElement  *frames_3;
    XMLElement  *xframe_3;


};

#endif // KUKAEXXMLMESSAGE_H

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
