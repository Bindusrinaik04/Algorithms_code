 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct Point {
    int x;
    int y;
};
typedef struct Point Point;

/* Swap function */
void swap(Point* a, Point* b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

int compareX(Point a, Point b) {
    return a.x - b.x;
}

/* Comparison function for sorting based on y-coordinates */
int compareY(Point a, Point b) {
    return a.y - b.y;
}

/* Calculate the Euclidean distance between two points */
float distance(Point p1, Point p2) {
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

/* Function to find the minimum of two float values */
float minimum(float x, float y) {
    return (x < y) ? x : y;
}

/* Bubble Sort implementation for sorting points based on x-coordinates */
void bubbleSortX(Point arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareX(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* Function to find the closest pair of points */
float closestPair(Point points[], Point xsort[], Point ysort[], int left, int right) {
    if (right - left + 1 <= 3) {
        float min = FLT_MAX;
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j <= right; ++j) {
                float dis = distance(points[i], points[j]);
                if (dis < min) {
                    min = dis;
                }
            }
        }
        return min;
    }

    int mid = (left + right) / 2;
    //Point leftp1, leftp2, rightp1, rightp2;
    float leftmin = closestPair(points, xsort, ysort, left, mid);
    float rightmin = closestPair(points, xsort, ysort, mid + 1, right);
    float mindis = minimum(leftmin, rightmin);

    Point strip[right - left + 1];
    int size = 0;

    for (int i = left; i <= right; i++) {
        if (abs(xsort[i].x - xsort[mid].x) < mindis)
            strip[size++] = xsort[i];
    }

    bubbleSortX(strip, size);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < mindis; j++) {
            float dist = distance(strip[i], strip[j]);
            if (dist < mindis) {
                mindis = dist;
            }
        }
    }

    return mindis;
}

int main() {
    int n;
    FILE* fp = fopen("points.txt", "r");

    if (!fp) {
        printf("Error while opening file\n");
        fclose(fp);
        return 1;
    }

    fscanf(fp, "%d\n", &n);

    if (n <= 1) {
        printf("Required at least two points\n");
        fclose(fp);
        return 1;
    }

    Point points[n];
    Point xsort[n], ysort[n];

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %d\n", &points[i].x, &points[i].y);
    }

    fclose(fp);

    for (int i = 0; i < n; i++) {
        xsort[i] = points[i];
        ysort[i] = points[i];
    }

    bubbleSortX(xsort, n);
    bubbleSortX(ysort, n);

    float mindis = closestPair(points, xsort, ysort, 0, n - 1);
    printf("Minimum distance = %f\n", mindis);

    return 0;
}

