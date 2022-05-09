#ifndef BINNODE_H
#define BINNODE_H
#include<iostream>
#include"string"
#include<queue>

using  namespace  std;

template<typename  E>
class  BinNode//结点类
{
private:
        BinNode*lc;//左孩子
        BinNode*rc;//右孩子
        E  elem;
public:
        BinNode()//默认构造函数，设置左右孩子为空
        {
                
           lc=NULL;
		   rc=NULL;                            //1

        }
        BinNode(E  tmp,  BinNode*l=NULL,  BinNode*r=NULL)//带参构造函数
        {
            elem=tmp;
			lc=l;
			rc=r;                                //2
        
        }
        BinNode*left()//返回左孩子
        {
            return lc;                               //3
        
        }
        BinNode*right()//返回右孩子
        {
            return rc;                        //4

        }
        void  setLeft(BinNode*l)//设置左孩子
        {
             lc=l;                            //5

        }
        void  setRight(BinNode*r)//设置右孩子
        {
             rc=r;                              //6

        }
        void  setValue(E  tmp)//设置当前结点的值
        {
                elem=tmp;                           //7

        }
        E  getValue()//获得当前结点的值
        {
                return elem;
                                                  //8
        }
        bool  isLeaf()//判断当前结点是否为叶子结点
        {
                if(lc==NULL&&rc==NULL)
                return true;
                else
                return false;
                                                   //9
        }
};


#endif
