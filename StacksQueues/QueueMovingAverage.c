typedef struct {
    int *queue;
    int maxSize;
    int head;
    long long windowSum;
    int count;
} MovingAverage;

MovingAverage* movingAverageCreate(int size) {
    MovingAverage* obj = (MovingAverage*) malloc(sizeof(MovingAverage));
    obj->queue = (int*) malloc(size * sizeof(int));
    obj->maxSize = size;
    obj->head = -1;
    obj->windowSum = 0;
    obj->count=0;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    obj->head = (obj->head + 1) % obj->maxSize;
    
    if (obj->count == obj->maxSize){
        obj->windowSum -= obj->queue[obj->head];
    } else {
        obj->count++;
    }
    
    obj->queue[obj->head] = val;
    obj->windowSum += val;
    
    return (double)obj->windowSum / obj->count;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/