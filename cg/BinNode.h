#ifndef BINNODE_H
#define BINNODE_H
#include<iostream>
#include"string"
#include<queue>

using  namespace  std;

template<typename  E>
class  BinNode//�����
{
private:
        BinNode*lc;//����
        BinNode*rc;//�Һ���
        E  elem;
public:
        BinNode()//Ĭ�Ϲ��캯�����������Һ���Ϊ��
        {
                
           lc=NULL;
		   rc=NULL;                            //1

        }
        BinNode(E  tmp,  BinNode*l=NULL,  BinNode*r=NULL)//���ι��캯��
        {
            elem=tmp;
			lc=l;
			rc=r;                                //2
        
        }
        BinNode*left()//��������
        {
            return lc;                               //3
        
        }
        BinNode*right()//�����Һ���
        {
            return rc;                        //4

        }
        void  setLeft(BinNode*l)//��������
        {
             lc=l;                            //5

        }
        void  setRight(BinNode*r)//�����Һ���
        {
             rc=r;                              //6

        }
        void  setValue(E  tmp)//���õ�ǰ����ֵ
        {
                elem=tmp;                           //7

        }
        E  getValue()//��õ�ǰ����ֵ
        {
                return elem;
                                                  //8
        }
        bool  isLeaf()//�жϵ�ǰ����Ƿ�ΪҶ�ӽ��
        {
                if(lc==NULL&&rc==NULL)
                return true;
                else
                return false;
                                                   //9
        }
};


#endif
