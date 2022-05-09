#include <iostream>
#include"BinNode.h"
#include"BinTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int  main()
{
        
        BinTree<string>*AT  =  new  BinTree<string>;
        BinTree<string>*BT =  new  BinTree<string>;
        creatBinaryTree(AT);
        creatBinaryTree(BT);
        string tree1;
        string tree2;
		
		AT->tree_to_string(tree1);
		BT->tree_to_string(tree2);
		
		if(tree1.find(tree2)!=-1 )
		{cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
        return  0;
}

