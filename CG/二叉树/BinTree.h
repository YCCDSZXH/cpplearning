#ifndef BINTREE_H
#define BINTREE_H
#include"BinNode.h"
template<typename  E>
class  BinTree//二叉树类
{
private:
        BinNode<E>*root;//根结点
        void  clear(BinNode<E>*r)//清空二叉树
        {
            if(r==NULL)return;
			clear(r->left());
			clear(r->right());
			delete r;    
                                                  //10
        }
        void  preOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//先序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
        {
            if(tmp==NULL)return;
			visit(tmp);
			preOrder(tmp->left(),visit);
			preOrder(tmp->right(),visit);   
                                                     //11
        }
        void  inOrder(  BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//中序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
        {
        	    if(tmp==NULL)return;
                inOrder(tmp->left(),visit);
                visit(tmp);
                inOrder(tmp->right(),visit);
                                                     //12
        }
        void  postOrder(BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//后序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
        {
        	   if(tmp==NULL)return;
			   postOrder(tmp->left(),visit);
			   postOrder(tmp->right(),visit);
			   visit(tmp);   
                                                       //13
        }
        void  LevelOrderTranverse(  BinNode<E>*tmp,void(*visit)(BinNode<E>*node))//层次遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
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
        int  BinTreeDepth(BinNode<E>*tmp)//获得二叉树的深度
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
        int  BinTreeNodes(BinNode<E>*tmp)//获得二叉树的结点数
        {
            if(tmp==NULL)return 0;
		int l=BinTreeNodes(tmp->left());    //左 
		int r=BinTreeNodes(tmp->right());   //右                                          //16
        int z=l+r+1;   
        return z;
        }
        int  BinTreeHeight(BinNode<E>*tmp)//获得二叉树的高度
        {
        	if(tmp==NULL)
        	return 0;
        	else{
        		int height=BinTreeDepth(tmp)+1;
				return height;
			}
                 
                                                             //17 0
        }
        int  BinTreeLeafs(BinNode<E>*tmp)//获得二叉树的叶子结点数
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
        bool  find(BinNode<E>*tmp,  E  e)//查找二叉树中是否含有某个名为e的结点
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
        BinTree()//默认构造函数
        {
                root=new  BinNode<E>;
        }
        ~BinTree()//析构函数
        {
                clear(root);
        }
        bool  BinTreeEmpty()//判断二叉树是否为空
        {
                if  (root  ==  NULL)
                        return  true;
                else
                        return  false;
        }
        BinNode<E>*getRoot()//获得根节点
        {
                return  root;
        }
        void  setRoot(BinNode<E>*r)//设置根节点
        {
                root  =  r;
        }
        //下面的函数是对外的函数，所以内部还会有一些同名的函数，但是参数列表不一样，实现数据的封装，外部的调用不会涉及到内部的数据对象
        void  clear()//清空二叉树
        {
                clear(root);
                root  =  NULL;
        }
        void  preOrder(void(*visit)(BinNode<E>*node))//先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
        {
                preOrder(root,visit);
        }
        void  inOrder(void(*visit)(BinNode<E>*node))  //先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
        {
                inOrder(root,visit);
        }
        void  postOrder(void(*visit)(BinNode<E>*node))//先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
        {
                postOrder(root,visit);
        }
        void  LevelOrderTranverse(void(*visit)(BinNode<E>*node))//先序遍历，传入相对应的访问函数即可对该当前结点实现不同功能的访问（本程序为输出）
        {
                LevelOrderTranverse(root,visit);
        }
        int  BinTreeDepth()//获得二叉树深度
        {
                return  BinTreeDepth(root);
        }
        int  BinTreeNodes()//获得二叉树结点数
        {
                return  BinTreeNodes(root);
        }
        void tree_to_string(string &s)
        {
        	return tree_to_string(root,s);
		}
        int  BinTreeHeight()//获得二叉树高度
        {
                return  BinTreeHeight(root);
        }
        int  BinTreeLeafs()//获得二叉树叶子结点数
        {
                return  BinTreeLeafs(root);
        }
        bool  find(E  e)//查找二叉树中是否存在名为e的结点
        {
                return  find(root,  e);
        }
};



template<typename  E>
void  printNode(BinNode<E>*tmp)//打印结点的值的函数
{
        cout  <<  tmp->getValue()  <<  "  ";
}

template<typename  E>
BinNode<E>*  creatBinaryTree(string  s,  int  &x,int  n)//构建二叉树的主函数，根据先序遍历，采用递归思想构建
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
void  creatBinaryTree(BinTree<string>*BT)//构建二叉树的函数，包含了上面的构建二叉树的主函数，仅仅起到了在主函数中简洁一些的作用
{
        string str;
        getline(cin,str);
        int  now  =  0;
        int n=str.size();
        BT->setRoot(creatBinaryTree<string>(str,now,n));
}
#endif
