/*

  mn_add.c
  
*/

#include <assert.h>

void mn_AppendSubtree(mn_type n, mn_type s)
{
  if ( n == NULL )
    return;
  if ( n->d == NULL
  {
    n->d = s;
    return;
  }
  n = n->d;
  while( n->n != NULL )
    n = n->n;
  n->n = s;
}

/*
  paste subtree s into tree n.
  s should be at postion pos
*/
void mn_PasteSubtree(mn_type n, int pos, mn_type s)
{
  assert( s->n == NULL );
  if ( pos == 0 )
  {
    s->n = n->d;
    n->d = s;
  }
  else
  {
    mn_type prev;
    prev = mn_GetSubtree(n, pos-1);
    if ( prev == NULL )
    {
      mn_AppendSubtree(n, s);
    }
    else
    {
      s->n = prev->n;
      prev->n = s;
    }
  }
  
}

