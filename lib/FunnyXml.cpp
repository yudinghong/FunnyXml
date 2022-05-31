//
// Created by Administrator on 2022/5/29.
//

#include "FunnyXml.h"
#include "FunnyNode.h"

FunnyXML::FunnyXml::FunnyXml() {
    this->lastErrCode = FUNNY_NO_ERROR;
    this->lastErrMessage = "";
}

FunnyXML::FunnyXmlDoc *FunnyXML::FunnyXml::parse(string xml) {
    FunnyXmlDoc *doc = new FunnyXmlDoc();
    int len = xml.size();
    FunnyNode *currentParseNode;
    PARSE_STATE parseState = PARSE_START;
    int row = 1;
    int col = 1;
    for(int i = 0; i < len;) {
        char c = xml[i];
        switch (parseState) {
            // 开始解析, 遇到空白字符跳过继续
            case PARSE_START: {
                if (isBlank(c)) {
                    i ++;
                    col ++;
                    continue;
                }
                else {

                }
                break;
            }
        }
    }
    return doc;
}

bool FunnyXML::FunnyXml::isBlank(char c) {
    if ((c >= '0' && c <= '0') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
    || c == '\'' || c == '\"' || c == '_' || c == '-' || c == ':' || c == '/') {
        return false;
    }
    else {
        return true;
    }
}
