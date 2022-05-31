//
// Created by Administrator on 2022/5/29.
//

#ifndef FUNNY_XML_FUNNYXML_H
#define FUNNY_XML_FUNNYXML_H

#include <string>

#include "./FunnyXmlDoc.h"
#include "./FunnyError.h"

using std::string;

namespace FunnyXML {
    class FunnyXml {
    public:
        FunnyXml();

        FunnyXmlDoc *parse(string xml);
        int getLastErrCode();
        string getLastErrMessage();

    private:
        void setError(int errCode);

        bool isBlank(char c);
        bool isLT(char c);
        bool isGT(char c);

    private:
        enum PARSE_STATE {PARSE_START, PARSE_TAG, PARSE_VERSION, PARSE_NODE, PARSE_END, PARSE_ERR};
        int lastErrCode;
        string lastErrMessage;
    };
}




#endif //FUNNY_XML_FUNNYXML_H
