class StockSpanner {
public:
    StockSpanner() {}
    stack<pair<int , int>>st; // ye isis liye kiya taki sabka span value aur main value ko sath me insert kr sake like for 100 its 1  and more over it would continue

    int next(int price) {
        int span = 1; // ye value humne default le li hai 
        // intusion
        /*
            yahan pr hum element ko store krte rshenge aur chek kareneg ki kahan current element ke liye stack ke top me humare pass small value hai aur span jo ki 1 hau usme +1 kr denge kyunki hr elemenet ka default 1 to rahega hi.Moreover hums span ko jo bara value tha jiske karan pop huausme store karenge aur return the span karenge         
        */
        while(!st.empty()){ // jabh tak stack empty na ho
            if(st.top().first<=price){ 
                span+=st.top().second;
                st.pop();
            }else{
                break; // for 80,1 after 100,1 the loop if condition wont work aur sedha ye element enter kr jayega kyunki  100 80 se bara hai.
            }
        }
        st.push({price,span});// pehle ye condition likhna parega kyunki agar stack empty hai to fir usme push the element karenge.
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */