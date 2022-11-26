#include <bits/stdc++.h>
using namespace std;

struct data {
    string product;
    int unit_price;
    int gst;
    int quantity;
    int gst_paid;
};

class Basket {
  public:
    vector<data> arr;
    int max_gst_paid;
    int cnt;
    int total_amt;
    int prodID;
    
    Basket(){
        max_gst_paid = INT_MIN;
        cnt = 0;
        total_amt = 0;
        prodID = 0;
    }
    
    void add_product(string prod,int unit,int gst,int quant){
        struct data product;
        product.product = prod;
        product.unit_price = unit;
        product.gst = gst;
        product.quantity = quant;
        
        if(product.unit_price >= 500){
            unit-= (unit*5)/100;
            product.unit_price = unit;
        }
        
        int gst_calc = (unit*gst)/100 * quant;
        product.gst_paid = gst_calc;
        arr.push_back(product);
        if(gst_calc > max_gst_paid){
            max_gst_paid = gst_calc;
            prodID = cnt;
        }
        cnt++;
        
        total_amt+= unit*quant + gst_calc;
    }
    
    string get_max_gst_paid(){
        return arr[prodID].product;
    }
    
    int get_total_amt(){
        return total_amt;
    }
};

int main() {
    Basket obj;
    obj.add_product("Leather Wallet",1100,18,1);
    obj.add_product("Umbrella",900,12,4);
    obj.add_product("Cigarette",200,28,3);
    obj.add_product("Honey",100,0,1);
    
    cout<<obj.get_max_gst_paid()<<endl;
    cout<<obj.get_total_amt();
    
    return 0;
    
}