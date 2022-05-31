//
// Created by Administrator on 2022/5/29.
//

#include "FunnyNode.h"
#include <stdio.h>

using std::to_string;
using std::stod;
using std::stoi;

FunnyXML::FunnyNode::FunnyNode() {
    this->isValidNode = false;
}

FunnyXML::FunnyNode::FunnyNode(string tagName) : tagName(tagName) {
    this->isValidNode = true;
}

FunnyXML::FunnyNode::FunnyNode(string tagName, vector<string> attributes) : tagName(tagName) {
    this->isValidNode = true;
}

FunnyXML::FunnyNode::FunnyNode(string tagName, map<string, string> attributes) {

}

void FunnyXML::FunnyNode::setTagName(string tagName) {

}

vector<FunnyXML::FunnyNode *> FunnyXML::FunnyNode::findChildrenByTagName(string tagName) {
    vector<FunnyNode *> vector;
    return vector;
}

FunnyXML::AttributeValue FunnyXML::FunnyNode::getAttribute(string attributeName) {
    map<string, AttributeValue>::iterator attributeIter = this->attributes.find(attributeName);
    if (attributeIter == this->attributes.end()) {
        AttributeValue value;
        return value;
    }
    else {
        return attributeIter->second;
    }
}

void FunnyXML::FunnyNode::addAttribute(string attributeName, string value) {
    this->attributes[attributeName] = value;
}

void FunnyXML::FunnyNode::addAttribute(string attributeName, int value) {
    this->attributes[attributeName] = value;
}

void FunnyXML::FunnyNode::addAttribute(string attributeName, double value) {
    this->attributes[attributeName] = value;
}

FunnyXML::AttributeValue &FunnyXML::FunnyNode::operator[](string key) {
    if (!this->hasAttribute(key)) {
        this->attributes[key] = AttributeValue();
    }
    return this->attributes[key];
}

bool FunnyXML::FunnyNode::hasAttribute(string attributeName) {
    return false;
}

void FunnyXML::FunnyNode::addChild(FunnyXML::FunnyNode *node) {

}

void FunnyXML::FunnyNode::insertChildBefore(int index, FunnyXML::FunnyNode *node) {

}

void FunnyXML::FunnyNode::insertChildAfter(int index, FunnyXML::FunnyNode *node) {

}

void FunnyXML::FunnyNode::insertBefore(FunnyXML::FunnyNode *node) {

}

void FunnyXML::FunnyNode::insertAfter(FunnyXML::FunnyNode *node) {

}

FunnyXML::AttributeValue::AttributeValue() : value("") {

}

FunnyXML::AttributeValue::AttributeValue(string value) {
    this->setValue(value);
}

FunnyXML::AttributeValue::AttributeValue(int value) {
    this->setValue(value);
}

FunnyXML::AttributeValue::AttributeValue(double value) {
    this->setValue(value);
}

void FunnyXML::AttributeValue::setValue(string value) {
    this->value = value;
}

void FunnyXML::AttributeValue::setValue(int value) {
    this->value = to_string(value);
}

void FunnyXML::AttributeValue::setValue(double value) {
    this->value = to_string(value);
}

string FunnyXML::AttributeValue::toString() {
    return this->value;
}

int FunnyXML::AttributeValue::toInt() {
    return stoi(this->value);
}

double FunnyXML::AttributeValue::toDouble() {
    return stod(this->value);
}

FunnyXML::AttributeValue &FunnyXML::AttributeValue::operator=(string value) {
    this->value = value;
    return *this;
}

FunnyXML::AttributeValue &FunnyXML::AttributeValue::operator=(int value) {
    this->value = std::to_string(value);
    return *this;
}

FunnyXML::AttributeValue &FunnyXML::AttributeValue::operator=(double value) {
    this->value = std::to_string(value);
    return *this;
}
