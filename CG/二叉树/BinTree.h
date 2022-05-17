#ifndef BINTREE_H
#define BINTREE_H
#include"BinNode.h"
template<typename  E>
class  BinTree//��������
{
private:
        BinNode<E>*root;//�����
        void  clear(BinNode<E>*r)//��ն�����
        {
            if(r==NULL)return;
			clear(r->left());
			clear(r->right());
			delete r;    
                                                  //10
        }
        void  preOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
        {
            if(tmp==NULL)return;
			visit(tmp);
			preOrder(tmp->left(),visit);
			preOrder(tmp->right(),visit);   
                                                     //11
        }
        void  inOrder(  BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
        {
        	    if(tmp==NULL)return;
                inOrder(tmp->left(),visit);
                visit(tmp);
                inOrder(tmp->right(),visit);
                                                     //12
        }
        void  postOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
        {
        	   if(tmp==NULL)return;
			   postOrder(tmp->left(),visit);
			   postOrder(tmp->right(),visit);
			   visit(tmp);   
                                                       //13
        }
        void  LevelOrderTranverse(  BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//��α�����void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
        {
                if(tmp==NULL)return;
				queue<BinNode<E>*>a;
				a.push(tmp);
				while(a.empty()!=1){
					BinNode<E>*b=a.front();
					visit(b);
					a.pop();
					if(b->left()!=NULL)
					a.push(b->left());
					if(b->right()!=NULL)
					a.push(b->right());
				}
                
                                                        //14
        }
        int  BinTreeDepth(BinNode<E>*tmp)//��ö����������
        {
                if(tmp==NULL)
				return 0; 
				queue<BinNode<E>*>b;
				b.push(tmp);
				int depth=0;
				while(b.empty()!=1){
					depth++;
				int x=b.size();
				int cout=0;
				while(cout<x){
					BinNode<E>*q=b.front();
					b.pop();
					cout++;
					if(q->left()!=NULL)
					b.push(q->left());
					if(q->right()!=NULL)
					b.push(q->right());
				}
				}                                       //15  0
                 return depth-1; 
				 
        }
        int  BinTreeNodes(BinNode<E>*tmp)//��ö������Ľ����
        {
            if(tmp==NULL)return 0;
		int l=BinTreeNodes(tmp->left());    //�� 
		int r=BinTreeNodes(tmp->right());   //��                                          //16
        int z=l+r+1;   
        return z;
        }
        int  BinTreeHeight(BinNode<E>*tmp)//��ö������ĸ߶�
        {
        	if(tmp==NULL)
        	return 0;
        	else{
        		int height=BinTreeDepth(tmp)+1;
				return height;
			}
                 
                                                             //17 0
        }
        int  BinTreeLeafs(BinNode<E>*tmp)//��ö�������Ҷ�ӽ����
        {
                if(tmp==NULL)return 0;
                else{
				
				if(tmp->left()==NULL&&tmp->right()==NULL)
				return 1+BinTreeLeafs(tmp->left())+BinTreeLeafs(tmp->right());
				else
				return BinTreeLeafs(tmp->left())+BinTreeLeafs(tmp->right());                                       //18
           }
        }
        void tree_to_string(BinNode<E>*tmp,string &s)
        {
        	if(tmp!=NULL)
        	{
        		s+=tmp->getValue();
        		tree_to_string(tmp->left(),s);
        		tree_to_string(tmp->right(),s);
			}
		}
        bool  find(BinNode<E>*tmp,  E  e)//���Ҷ��������Ƿ���ĳ����Ϊe�Ľ��
        {
                if(tmp==NULL)return false;
                else{
                if(tmp->getValue()==e)
                return true;
                else{
               if(find(tmp->left(),e)==1)
               return true;
               if(find(tmp->right(),e)==1)
               return true;
               
               return false; 
			   } 
				}
               
               
                                                                   //19
        }
public:
        BinTree()//Ĭ�Ϲ��캯��
        {
                root=new  BinNode<E>;
        }
        ~BinTree()//��������
        {
                clear(root);
        }
        bool  BinTreeEmpty()//�ж϶������Ƿ�Ϊ��
        {
                if  (root  ==  NULL)
                        return  true;
                else
                        return  false;
        }
        BinNode<E>*getRoot()//��ø��ڵ�
        {
                return  root;
        }
        void  setRoot(BinNode<E>*r)//���ø��ڵ�
        {
                root  =  r;
        }
        //����ĺ����Ƕ���ĺ����������ڲ�������һЩͬ���ĺ��������ǲ����б�һ����ʵ�����ݵķ�װ���ⲿ�ĵ��ò����漰���ڲ������ݶ���
        void  clear()//��ն�����
        {
                clear(root);
                root  =  NULL;
        }
        void  preOrder(void(*visit)(BinNode<E>*node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
        {
                preOrder(root,visit);
        }
        void  inOrder(void(*visit)(BinNode<E>*node))  //����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
        {
                inOrder(root,visit);
        }
        void  postOrder(void(*visit)(BinNode<E>*node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
        {
                postOrder(root,visit);
        }
        void  LevelOrderTranverse(void(*visit)(BinNode<E>*node))//����������������Ӧ�ķ��ʺ������ɶԸõ�ǰ���ʵ�ֲ�ͬ���ܵķ��ʣ�������Ϊ�����
        {
                LevelOrderTranverse(root,visit);
        }
        int  BinTreeDepth()//��ö��������
        {
                return  BinTreeDepth(root);
        }
        int  BinTreeNodes()//��ö����������
        {
                return  BinTreeNodes(root);
        }
        void tree_to_string(string &s)
        {
        	return tree_to_string(root,s);
		}
        int  BinTreeHeight()//��ö������߶�
        {
                return  BinTreeHeight(root);
        }
        int  BinTreeLeafs()//��ö�����Ҷ�ӽ����
        {
                return  BinTreeLeafs(root);
        }
        bool  find(E  e)//���Ҷ��������Ƿ������Ϊe�Ľ��
        {
                return  find(root,  e);
        }
};



template<typename  E>
void  printNode(BinNode<E>*tmp)//��ӡ����ֵ�ĺ���
{
        cout  <<  tmp->getValue()  <<  "  ";
}

template<typename  E>
BinNode<E>*  creatBinaryTree(string  s,  int  &x,int  n)//������������������������������������õݹ�˼�빹��
{
        if  (s[x]  =='#')
                return  NULL;
        else
        {
                BinNode<E>*node  =  new  BinNode<E>(&s[x]); 
                x  =  x  +  1;
                if  (x  <  n);
                node->setLeft(creatBinaryTree<E>(s,  x,n));
                x  =  x  +  1;
                if  (x  <  n);
                node->setRight(creatBinaryTree<E>(s,  x,n));
                return  node;
        }
}
void  creatBinaryTree(BinTree<string>*BT)//�����������ĺ���������������Ĺ������������������������������������м��һЩ������
{
        string str;
        getline(cin,str);
        int  now  =  0;
        int n=str.size();
        BT->setRoot(creatBinaryTree<string>(str,now,n));
}
#endif
