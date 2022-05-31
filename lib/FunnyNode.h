//
// Created by Administrator on 2022/5/29.
//

#ifndef FUNNY_XML_FUNNYNODE_H
#define FUNNY_XML_FUNNYNODE_H

#include <string>
#include <map>
#include <list>
#include <vector>

#include "./FunnyStruct.h"

using std::map;
using std::list;
using std::vector;
using std::string;

namespace FunnyXML {
    class AttributeValue {
    public:
        AttributeValue();
        AttributeValue(string value);
        AttributeValue(int value);
        AttributeValue(double value);
        void setValue(string value);
        void setValue(int value);
        void setValue(double value);
        AttributeValue &operator = (string value);
        AttributeValue &operator = (int value);
        AttributeValue &operator = (double value);
        string toString();
        int toInt();
        double toDouble();

    private:
        string value;
    };

    class FunnyNode {
    public:
        // 构造节点
        FunnyNode();
        FunnyNode(string tagName);
        FunnyNode(string tagName, vector<string> attributes);
        FunnyNode(string tagName, map<string, string> attributes);
        // 如果是非有效节点
        void setTagName(string tagName);

        // 查找子元素
        vector<FunnyNode *> findChildrenByTagName(string tagName);
        // 属性操作
        AttributeValue getAttribute(string attributeName);
        void addAttribute(string attributeName, string value);
        void addAttribute(string attributeName, int value);
        void addAttribute(string attributeName, double value);
        AttributeValue & operator [](string key);
        bool hasAttribute(string attributeName);
        // 添加子节点
        void addChild(FunnyNode *node);
        void insertChildBefore(int index, FunnyNode *node);
        void insertChildAfter(int index, FunnyNode *node);
        void insertBefore(FunnyNode *node);
        void insertAfter(FunnyNode *node);

    public:
        FunnyNode *parent;
        FunnyNode *preSibling;
        FunnyNode *nextSibling;

    private:
        enum NODE_PARSE_STATE {
            PARSE_START,
            PARSE_END
        };
        string tagName;
        map<string, AttributeValue> attributes;
        // 去除标签的文本内容
        string content;
        vector<FunnyNode *> children;
        NODE_PARSE_STATE parseState;
        bool isValidNode;
        vector<XML_Namespace> namespaces;
    };

}

#endif //FUNNY_XML_FUNNYNODE_H
