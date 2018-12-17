import java.util.*;

public class AVLTree  {
  
  /** Root of the AVL tree. */
  protected AVLNode root;

  /**
   * AVLTree constructor that initializes the underlying binary
   * search tree with just a null, which is the root.
   */
  public AVLTree()  {
    root = null;
  }
  
  /**
   * Searches the tree for a node with a given key. If such a node exists,
   * prints the value of that node. 
   */
  public String search(int k)  {
    AVLNode node = search(root,k);
    System.out.println(" " + node.printNode());
    return node.data;
  }

  /**
   * Searches the subtree rooted at a given node for a node with a given key.  
   * An exception NoSuchElementException is thrown if no node exists.
   */
  protected AVLNode search(AVLNode node, int k)   {
    while ((node != null) && (k != node.key)) {
            if (k < node.key)
                node = node.left;
            else
                node = node.right;
     }

     if (node != null){
       return node; }
     else {
       throw new NoSuchElementException("Not Found"); }
  }

  /**
   * Returns the node with the minimum key in the subtree rooted at
   * a node.
   */
  
  protected AVLNode treeMinimum(AVLNode x)  {
    while (x.left != null)
      x = x.left;
    
    return x;
  }
  
  /**
   * Returns the successor of a given node in an inorder walk of the
   * tree.
   */
  
  protected AVLNode successor(AVLNode node)  {
    AVLNode x = node;
    
    if (x.right != null)
      return treeMinimum(x.right);
    
    AVLNode y = x.parent;
    while (y != null && x == y.right) {
      x = y;
      y = y.parent;
    }
    
    return y;
  }
  
  /**
   * Performs single left rotation.
   */ 
   protected void singleLeftRotation(AVLNode z)   {
	   AVLNode parent = z.parent;
	   AVLNode y = z.right;
	   if (y==null) {
		   return;
	   }
	   
	   AVLNode t2 = y.left;
	   y.left = z;
	   z.right = t2;
	   z.parent = y;
	   y.parent = parent;
	   if(parent == null) {
		   root = y;
	   }else {
		   y.parent.right = y;
	   }
	   z.bf = height(z.left) - height(z.right);
	   y.bf = height(y.left) - height(y.right);
   }
   
   /**
   * Performs single right rotation.
   */ 
   protected void singleRightRotation(AVLNode z)   {
	   AVLNode parent = z.parent;
	   AVLNode y = z.left;
	   if (y==null) {
		   return;
	   }
	   AVLNode t3 = y.right;
	   y.right = z;
	   z.left = t3;
	   z.parent = y;
	   y.parent = parent;
	   
	   if(parent == null) {
		   root = y;
	   }else {
		   y.parent.left = y;
	   }
	   
	   z.bf = height(z.left) - height(z.right);
	   y.bf = height(y.left) - height(y.right);   
   }
   
   /**
   * Performs double right left rotation.
   */ 
   protected void doubleRightLeftRotation(AVLNode A)   {
	   singleRightRotation(A.right);
	   singleLeftRotation(A);
   }
   
   /**
   * Performs double left right rotation.
   */ 
   protected void doubleLeftRightRotation(AVLNode A)   {
	   singleLeftRotation(A.left);
	   singleRightRotation(A);
   }
   
   /** Balances a right-heavy or left-heavy unbalanced tree.
    * This function should check for the nature of the imbalance
    * and call the appropriate rotation functions. In addition, after
    * rotations are performed,
    * it should update the balance factors of the rotated nodes accordingly. 
    */
   protected AVLNode balance(AVLNode A)   {

	   if(A.bf > 1){
		   if(A.left.bf>0){
			   singleRightRotation(A);
		   }else{
			   doubleLeftRightRotation(A);
		   }
	   }else if(A.bf < -1){
		   if(A.right.bf<0){
				   singleLeftRotation(A);
			   }else{
				   doubleRightLeftRotation(A);
			   }
		   }
	   
	   checkBalance(A);
	   return A;
   }
   
  /**
   * Inserts a key and a data item into the tree, creating a new 
   * node for this key and data pair.
   */
  public void insert(int key, String data)  {
    AVLNode z = new AVLNode(key, data);
    treeInsert(z);
  }
  
  /**
   * Inserts a node into the tree.
   */
  protected void treeInsert(AVLNode z)  {
	    AVLNode y = null;
	    AVLNode x = root;
	    
	    while (x != null) {
	      y = x;
	      if (z.key <= x.key)
	        x = x.left;
	      else
	        x = x.right;
	    }
	    
	    z.parent = y;
	    if (y == null){
		      root = z; // the tree had been empty
		      z.bf=0; 
		      return;
	    }else {
	      if (z.key <= y.key)
	        y.left = z;
	      else
	        y.right = z;
	    }
	   
    //TO DO: Insert code to update balance factors and 
    //perform rotations if necessary.
	    
	    checkBalance(z);
 }
  
  public void checkBalance(AVLNode A){
	  	if(A==null || root==null)
	  		return;
  		int bf = height(A.left) - height(A.right);
  		A.bf = bf;
  		 		
  		if((A.bf > 1) || (A.bf < -1)||(root.bf > 1) || (root.bf < -1)){
  			balance(A);
  		}
  		
	    if(A.parent == null){ //base case
	    	System.out.println(A.data);
	    	return;
	    }else{
	    	//for testing System.out.println(A.parent.data + " is parent of "+A.data);
	    	checkBalance(A.parent); //keep moving up the tree
	    }
  }

	public int height(AVLNode A){
		
		if(A == null){
			return 0;
		}

		int LSubTree = height(A.left) + 1;
		int RSubTree = height(A.right) + 1;
		
		if(LSubTree > RSubTree){
			return LSubTree;
		}else{
			return RSubTree;	
		}

	}

  /**
   * Removes a node with the given key from the tree.
   * It is assumed that there is at most one node with the given
   * key present in the tree.
   */
  public void deleteKey(int k)  {
    AVLNode node = (AVLNode) search(root, k);
    if (node != null)
      delete(node);
    else
      throw new NoSuchElementException("Not Found");
  }

  /**
   * Removes a node from the tree.
   */
  protected void delete(AVLNode node)  {
    // TO DO: Alter and add code to this function to support
    // AVL deletions

    AVLNode z = node;
    
    // Make sure that there is no attempt to delete a null node
    if (z == null)
      throw new NoSuchElementException("empty node");
    
    AVLNode x;   // Replaces z as the subtree's root
    
    if (z.left == null){   // has no left child
      x = z.right;
    }
    else if (z.right == null) // has no right child
      x = z.left;
    else {                 // has two children 
      x = (AVLNode) successor(z); // replace z with its successor  
      delete(x); // Delete the node where the successor was 
      
      // Splice out z and put x in its place by fixing links
      // with children.
      x.left = z.left; 
      x.right = z.right;
      if (x.left != null) x.left.parent = x;
      if (x.right != null) x.right.parent = x;
    } //else
    
    // Fix links between the parent of the subtree and x.
    if (x != null)
      x.parent = z.parent;
    if (root == z)
      root = x;
    else{
      if (z == z.parent.left)
          z.parent.left = x;
      else
          z.parent.right = x;
    } //else

    // TO DO: Insert code to update balance factors and
    // rebalance tree
    
    checkBalance(z);
  }


  /**
   * Print the whole tree.
   */
  public void print() {
    printHelper(root,0);
    System.out.print("\n");
  }
  
  /**
   * Print the tree rooted at <code>root</code>, with indent preceding 
   * all output lines.
   * The tree is printed rotated by 90 degrees.  
   * If there is no node at a given position of the tree, the 
   * character 'x' is printed. 
   *
   * WARNING: DO NOT MODIFY THIS METHOD!!!
   */
  protected static void printHelper(AVLNode n, int indent) {
    
    String blanks="";
    for (int i=0;i<indent;++i) blanks=blanks+" ";
    
    if (n == null) {
      System.out.println(blanks+"x");
      return;
    }
    
    printHelper(n.right, indent+n.printNode().length());
    System.out.println(blanks+n.printNode());
    printHelper(n.left, indent+n.printNode().length());
 
  }
  
  protected static void inorder(AVLNode n) {
	  if(n==null)
		  return;
	  
	  inorder(n.left);
	  System.out.print(n.printNode()+" test");
	  inorder(n.right);
  }
  
  /**
   * Print the tree rooted at <code>root</code>, with indent preceding 
   * all output lines.
   * The tree is printed rotated by 90 degrees. Bars ("|")are 
   * added to indicate the parent node edges. It is memory-intensive,
   * so for large trees the integer version is recommended. 
   * If there is no node at a given position of the tree, the 
   * character 'x' is printed. 
   *
   * WARNING: DO NOT MODIFY THIS METHOD!!!
   */
  private static void printHelper(AVLNode n, String indent) {
    
   
    if (n == null) {
      System.out.println(indent+"x");
      return;
    }
   
    String blanks="";
    for (int i=0;i<n.printNode().length();++i) blanks=blanks+" ";
    String barandblanks="|";
    for (int i=0;i<n.printNode().length()-1;++i) barandblanks = barandblanks+" ";

    if (n.parent == null) //root
    {
      printHelper(n.right, indent+blanks);
      System.out.println(indent+"*"+n.printNode());
      printHelper(n.left, indent+blanks);
      return;
    } 
    
    if (n.parent.left == n)
    {
      printHelper(n.right, indent+barandblanks);
      System.out.println(indent+"|"+n.printNode());
      printHelper(n.left, indent+blanks);
    } else
    {
      printHelper(n.right, indent+blanks);
      System.out.println(indent+"|"+n.printNode());
      printHelper(n.left, indent+barandblanks);
    }
  }

  
 /**
  * Prints out the content of the tree in an inorder traversal manner.
  */
  public String inOrder() {
    return ("Inorder-traversal content of the tree:" + inOrder(root));
 }
   
  
 /**
  * Collects the content of the tree by performing an inorder traversal walk.
  */
  private String inOrder(AVLNode n) {
     if (n == null) return "";
     String returnString = inOrder(n.left);
     returnString += " { " + n.key + " -> " + n.data + " }";
     return returnString + inOrder(n.right); 
  }
  
}