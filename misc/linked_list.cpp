// Deletions and insertions in O(1)
// A node contains data and link to previous and next elements
struct node{
  public:
    int l, r, d;
}A[1000000];

// Delete a node to the left of the node with index i
int delete_left(int i){
  int ret = -1;
  if(A[i].l == -1)
    return ret;
  else if(A[A[i].l].l == -1){
    ret = A[A[i].l].d;
    A[i].l = -1;
    return ret;
  }
  else{
    ret = A[A[i].l].d;
    A[i].l = A[A[i].l].l;
    A[A[i].l].r = i;
    return ret;
  }
}

// Delete a node to the right of the node with index i
int delete_right(int i){
  int ret = -1;
  if(A[i].r == -1)
    return ret;
  else if(A[A[i].r].r == -1){
    ret = A[A[i].r].d;
    A[i].r = -1;
    return ret;
  }
  else{
    ret = A[A[i].r].d;
    A[i].r = A[A[i].r].r;
    A[A[i].r].l = i;
    return ret;
  }
}

// Delete the node at location i
bool delete_pos(int i){
  if(A[i].l == -1 && A[i].r == -1)
    return false;
  else if(A[i].l == -1){
    A[A[i].r].l = -1;
    return true;
  }
  else if(A[i].r == -1){
    A[A[i].l].r = -1;
    return true;
  }
  else{
    A[A[i].l].r = A[i].r; 
    A[A[i].r].l = A[i].l;
    return true;
  }
}
