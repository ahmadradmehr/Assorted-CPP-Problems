/* Rectangle Area
 * 
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * 
 * Example:
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * Assume that the total area is never beyond the maximum possible value of int.
 */
 
class RectangleArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int intersect;
        if (E > C || F > D || H < B || G < A)
            intersect = 0;
        else {
            int x1 = max(A, E);
            int y1 = max(B, F);
            int x2 = min(C, G);
            int y2 = min(D, H);
            intersect = (x2 - x1) * (y2 - y1);
        }
        return (C - A) * (D - B) - intersect + (G - E) * (H - F);
    }
};