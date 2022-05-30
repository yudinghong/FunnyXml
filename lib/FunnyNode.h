//
// Created by Administrator on 2022/5/29.
//

#ifndef FUNNY_XML_FUNNYNODE_H
#define FUNNY_XML_FUNNYNODE_H

#include <string>
#include <map>
#include <list>
#include <vector>

using std::map;
using std::list;
using std::vector;

namespace FunnyXML {
    class AttributeValue {
    public:
        AttributeValue(string value);
        void toString();
        void toInt();
        void toDouble();

    private:
        string value;
    };

    class FunnyNode {
    public:
        // 构造节点
        FunnyNode(string xml);
        FunnyNode(string tagName, vector<string> attributes);
        FunnyNode(string tagName, map<string, string> attributes);
        // 查找子元素
        vector<FunnyNode> findChildrenByTagName(string tagName);
        // 属性操作
        AtrributeValue getAttribute(string attributeName);
        void addAttribute(string attributeName, string value);
        void addAttribute(string attributeName, int value);
        void addAttribute(string attributeName, double value);
        AttributeValue & operator [](string key);
        bool hasAttribute(string attributeName);
        // 添加子节点
        void addChild(FunnyNode node);
        void insertBefore(int index, FunnyNode node);
        void insertAfter(int index, FunnyNode node);

    private:
        string tagName;
        map<string, AttributeValue> attribute;
        // 去除标签的文本内容
        string content;
        vector<FunnyNode> children;
    };

}

#endif //FUNNY_XML_FUNNYNODE_H
