/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(first[curDim]>second[curDim])
      return false;
    else if(first[curDim]==second[curDim])
      return (first<second);
    else
      return true;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     int currentDistance= distance(target,currentBest);
     int potentialDistance= distance(target,potential);
     if(currentDistance<potentialDistance)
     return false;
     else if(potentialDistance<currentDistance)
     return true;
     else
     return potential<currentBest;
}
template<int Dim>
int KDTree<Dim>::distance(const Point<Dim>& target,const Point<Dim>& query)const {
  int dist=0;
  for(int i=0;i< Dim;i++)
    dist+=(target[i]-query[i])*(target[i]-query[i]);
  return dist;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
  size=newPoints.size();
  if(size==0)
    root=NULL;
  else{
    for(const Point<Dim>& i: newPoints){
      treepoints.push_back(i);
    }
    root= build(0,size-1,0);
  }

}
template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::build(int begin, int end,int currentDim){
  if(begin>end)//leaf
    return NULL;
  else if(begin==end)
    return new KDTreeNode(treepoints[begin]);
  else{
    int pivotIndex=(begin+end)/2;
    int nextDim=(currentDim+1)%Dim;
    quickSelect(begin,end,pivotIndex,currentDim);

    KDTreeNode *  currentRoot= new KDTreeNode(treepoints[pivotIndex]);
    currentRoot->left = build(begin,(pivotIndex-1), nextDim);
    currentRoot->right = build((pivotIndex+1), end, nextDim);

    return currentRoot;
  }
}

template <int Dim>
void KDTree<Dim>::quickSelect(int begin, int end, int pivotIndex, int currentDim) {
  while(begin!=end){
    Point<Dim> pivotPoint=treepoints[pivotIndex];
    treepoints[pivotIndex]=treepoints[end];
    treepoints[end]=pivotPoint;
    int storeIndex=begin;
    for(int i=begin;i<end;i++){
      if(smallerDimVal(treepoints[i],pivotPoint,currentDim) || treepoints[i]==pivotPoint){
        Point<Dim> temp=treepoints[storeIndex];
        treepoints[storeIndex]=treepoints[i];
        treepoints[i]=temp;
        storeIndex++;
      }
    }
    Point<Dim> temp=treepoints[storeIndex];
    treepoints[storeIndex]=treepoints[end];
    treepoints[end]=temp;
    if(storeIndex==pivotIndex)
      return;
    else if (pivotIndex < storeIndex)
      end = storeIndex-1;
    else
      begin = storeIndex+1;
  }
}


template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   copy(other);
}

template <int Dim>
void KDTree<Dim>::copy(const KDTree<Dim>& other){
  this=new KDTree(other.treepoints);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
   if(*this!=rhs){
     destroy();
     copy(rhs);
   }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   destroy();
}

template <int Dim>
void KDTree<Dim>::destroy(){
  for(size_t i=0;i<size;i++)
    treepoints.pop_back();
  size=0;
  destroyHelper(root);
}

template <int Dim>
void KDTree<Dim>::destroyHelper(typename KDTree<Dim>::KDTreeNode* subRoot){
  if(subRoot==NULL)
    return;
  destroyHelper(subRoot->left);
  destroyHelper(subRoot->right);
  delete subRoot;
  subRoot=NULL;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return findNearestNeighbor(query,root,0);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query,typename KDTree<Dim>::KDTreeNode* currentNode, int currentDim) const{
  if(currentNode->left==NULL && currentNode->right==NULL)
   return currentNode->point;
  int nextDim=(currentDim+1)%Dim;
  Point<Dim> currentBest= currentNode->point;
  Point<Dim> potentialBest= currentBest;
  bool direction=smallerDimVal(query,currentBest,currentDim);
  if(direction && currentNode->left!=NULL){
    potentialBest= findNearestNeighbor(query,currentNode->left,nextDim);
  }
  else if(!direction && currentNode->right!=NULL){
    potentialBest= findNearestNeighbor(query,currentNode->right,nextDim);
  }

  if(shouldReplace(query,currentBest,potentialBest))
    currentBest=potentialBest;

  int bestDistance=distance(query,currentBest);
  int dimDistance= (query[currentDim] - currentNode->point[currentDim])*(query[currentDim] - currentNode->point[currentDim]);
  if(dimDistance<=bestDistance){
    if(!direction && currentNode->left!=NULL){
      potentialBest= findNearestNeighbor(query,currentNode->left,nextDim);
      if(shouldReplace(query,currentBest,potentialBest))
        currentBest=potentialBest;
    }
    else if(direction && currentNode->right!=NULL){
      potentialBest= findNearestNeighbor(query,currentNode->right,nextDim);
      if(shouldReplace(query,currentBest,potentialBest))
        currentBest=potentialBest;
    }
  }
  return currentBest;
 }
