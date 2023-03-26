// thuat toan quay lui
// markRow[9][10] markRow[r][v]=Truwe co nghia la v da xuat hien tren hang r
// markCol[9][10] markCol[r][v]=Truwe co nghia la v da xuat hien tren cot r
/* try(r,c) 
      for v= 1 ->  9 do
        if check(v,r,c) then
          x[r,c] = v;
          markRow[r.v]=True;
          markCol[c,v]=True;
          markSquare[r/3,c/3,v] = True;
          if r=8 and c=8 then solution;
          else {
            if c<8 then Try(r,c+1);
            else Try(r+1,0);
          }
          markRow[r,v]=False;
          markCol[c,v]]=False;
          markSquare[r/3,c/3,v]=False;
    check(v,r,c){
        return markRow[r,v]=False
        and markCol[c,v]=False
        and markSquare[r/3;c/3,v]=False;
    }
    main{
        Danh dau false
    }      
*/
#include<stdio.h>
int main(){

}