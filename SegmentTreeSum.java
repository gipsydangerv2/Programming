import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    class SegmentTree {
        int tree[];
        int elements[];
        int nodes, treeSize;

        private void initializeTree(int elements[]) {
            this.elements = elements;
            this.nodes = elements.length;
            this.treeSize = getTreeSize(nodes);
            tree = new int[2 * treeSize];
            buildTree(1, 0, nodes - 1);
        }

        private int getTreeSize(int nodes) {
            int size = 1;
            for (; nodes > size; size <<= 1) ;
            return size;
        }

        private void buildTree(int vertex, int treeLeft, int treeRight) {
            if (treeLeft == treeRight) {
                tree[vertex] = elements[treeLeft];
            } else {
                int middle = treeLeft + (treeRight - treeLeft) / 2;
                buildTree(2 * vertex, treeLeft, middle);
                buildTree(2 * vertex + 1, middle + 1, treeRight);
                tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
            }
        }

        private long queryTree(int vertex, int treeLeft, int treeRight, int queryLeft, int queryRight) {
            if (queryLeft > queryRight) {
                return 0;
            }
            if (treeLeft == queryLeft && treeRight == queryRight) {
                return tree[vertex];
            } else {
                int middle = treeLeft + (treeRight - treeLeft) / 2;
                return queryTree(2 * vertex, treeLeft, middle, queryLeft, Math.min(queryRight, middle)) +
                        queryTree(2 * vertex + 1, middle + 1, treeRight, Math.max(queryLeft, middle + 1), queryRight);

            }
        }

        private void updateTree(int vertex, int treeLeft, int treeRight, int idx, int value) {
            if (treeLeft == treeRight) {
                tree[treeLeft] = value;
            } else {
                int middle = treeLeft + (treeRight - treeLeft) / 2;
                if (idx <= middle) {
                    updateTree(2 * vertex, treeLeft, middle, idx, value);
                } else {
                    updateTree(2 * vertex + 1, middle + 1, treeRight, idx, value);
                }
                tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
            }
        }

    }

    public void solve() throws IOException {
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(buff.readLine());
        String[] input = buff.readLine().split(" ");
        int arr[] = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        SegmentTree tree = new SegmentTree();
        tree.initializeTree(arr);
        int query = Integer.parseInt(buff.readLine());
        int queryType, val1, val2;
        for (int i = 0; i < query; i++) {
            input = buff.readLine().split(" ");
            queryType = Integer.parseInt(input[0]);
            val1 = Integer.parseInt(input[1]);
            val2 = Integer.parseInt(input[2]);
            // 1: update query, 2 : range sum query.
            if (queryType == 1) {
                tree.updateTree(1, 0, n - 1, val1 , val2);
            }
            else if(queryType == 2) {
                System.out.println(tree.queryTree(1, 0, n - 1, val1, val2));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Solution solution = new Solution();
        solution.solve();
    }
}
