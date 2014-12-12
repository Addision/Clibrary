/*
 * Filename: lib_filexml.c
 *                
 * Version:       
 * Author:        LaiJia <laijia2008@126.com>
 * Created at:    Mon Oct 20 23:00:03 2014
 *                
 * Description:   
 *
 */

#include "lib_filexml.h"

int lib_filexml_create(const char *filepath,const char *root)
{
	xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
	xmlNodePtr rootnode = xmlNewNode(NULL, BAD_CAST root);
	xmlDocSetRootElement(doc, rootnode);

	int ret = xmlSaveFile(filepath, doc);
	if(ret > 0)
	{
		printf("the file is created\n");
	}
	xmlFreeDoc(doc);

	return 1;
}
