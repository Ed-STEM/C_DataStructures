/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/

#define MAX_SIZE 100000

typedef struct {
    int *prices;
    int *spans;
    int top;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->prices = (int*)malloc(MAX_SIZE*sizeof(int));
    obj->spans = (int*)malloc(MAX_SIZE*sizeof(int));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    
    int count = 1;

    while(obj->top >= 0 && obj->prices[obj->top] <= price){
        count += obj->spans[obj->top];
        obj->top--;
    }
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = count;

    return count;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->spans);
    free(obj);
}
