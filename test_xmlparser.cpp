 //<?xml version="1.0" encoding="ISO-8859-1"?>
 //<PMML version="3.0"
 //  xmlns="http://www.dmg.org/PMML-3-0"
 //  xmlns:xsi="http://www.w3.org/2001/XMLSchema_instance" >
 //  <Header copyright="Frank Vanden Berghen">
 //     Hello World!
 //  <Application name="&lt;Condor>" version="1.99beta" />
 //  </Header>
 //  <Extension name="keys"> <Key name="urn"> </Key> </Extension>
 //  <DataDictionary>
 //    <DataField name="persfam" optype="continuous" dataType="double">
 //       <Value value="9.900000e+001" property="missing" />
 //    </DataField>
 //    <DataField name="prov" optype="continuous" dataType="double" />
 //    <DataField name="urb" optype="continuous" dataType="double" />
 //    <DataField name="ses" optype="continuous" dataType="double" />
 //  </DataDictionary>
 //  <RegressionModel functionName="regression" modelType="linearRegression">
 //    <RegressionTable intercept="0.00796037">
 //      <NumericPredictor name="persfam" coefficient="-0.00275951" />
 //      <NumericPredictor name="prov" coefficient="0.000319433" />
 //      <NumericPredictor name="ses" coefficient="-0.000454307" />
 //      <NONNumericPredictor name="testXmlExample" />
 //    </RegressionTable>
 //  </RegressionModel>
 //</PMML>
 //
 
 test_1:
 
#include <stdio.h>    // to get "printf" function
#include <stdlib.h>   // to get "free" function
#include "xmlparser.h"

int main(int argc, char **argv)
{
	
	// this open and parse the XML file:
	XMLNode xMainNode=XMLNode::openFileHelper("haha.xml","PMML");

	// this prints "<Condor>":
	XMLNode xNode=xMainNode.getChildNode("Header");
	printf("Application Name is: '%s'\n", xNode.getChildNode("Application").getAttribute("name"));
    printf("get name:%s\n", xNode.getChildNode("Application").getName());
	// this prints "Hello world!":
	printf("Text inside Header tag is :'%s'\n", xNode.getText());

	// this gets the number of "NumericPredictor" tags:
	xNode=xMainNode.getChildNode("RegressionModel").getChildNode("RegressionTable");
	int n=xNode.nChildNode("NumericPredictor");

	// this prints the "coefficient" value for all the "NumericPredictor" tags:
	for (int i=0; i<n; i++)
		printf("coeff %i=%f\n",i+1,atof(xNode.getChildNode("NumericPredictor",i).getAttribute("coefficient")));

	// this prints a formatted ouput based on the content of the first "Extension" tag of the XML file:
	char *t=xMainNode.getChildNode("Extension").createXMLString(true);
	printf("%s\n",t);
	free(t);
	//	createXMLTopNode("hahaha", true);
	
	return 0;
}

test_2:
	
#include <iostream>
#include <cstdio>
#include "xmlparser.h"
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

void getnodename(XMLNode &xnode, char* xmltree);
int main(int argc, char *argv[])
{
    XMLNode xmlMainNode = XMLNode::parseFile("haha.xml");
	const char* strxml = xmlMainNode.getName();
	if(strcmp(strxml, "xml") != 0)
	{
		fprintf(stderr, "load xml error\n");
		return -1;
	}
	XMLNode childnode = xmlMainNode.getChildNode("PMML");
	// XMLNode node1 = childnode.getChildNode("Header");
	// printf("get name is:%s\n", node1.getName());
    getnodename(childnode, "RegressionModel/RegressionTable/NumericPredictor");
    return 0;
}

void getnodename(XMLNode &xnode, char* xmltree)
{
	XMLNode node = xnode;
	string workpath = xmltree;
	string strname = "";
	while(workpath.length())
	{
		int pos = workpath.find("/");
		if(pos == string::npos)
		{
			strname = workpath;
			workpath = "";
		}
		else
		{
			strname = workpath.substr(0, pos);
			workpath = workpath.substr(pos+1);
		}
		// int n = node.nChildNode(strname.c_str());
		// for(int i=0;i<n;++i)
		// {
		// 	printf("the node name:%s\n", node.getAttribute("name"));			
		// }
		node = node.getChildNode(strname.c_str());
		printf("the node name:%s\n", node.getName());			
	}


}
