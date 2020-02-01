import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
    public static String input[];
	public static void main (String[] args) throws IOException
	{
	    BufferedReader buff = new BufferedReader(new InputStreamReader(System.in)); 
	    input = buff.readLine().split(" ");
	    int t = Integer.parseInt(input[0]);
	    while(t-- > 0) {
	        input = buff.readLine().split(" ");
	        int n = Integer.parseInt(input[0]);
	        input = buff.readLine().split(" ");
	        int []arr = new int[n];
	        for(int i=0;i<n;i++)
	            arr[i] = Integer.parseInt(input[i]);
	        System.out.println(GFG.getLongestBitonicSeq(arr,n));
	    }
	    
	}
	
	public static int getLongestBitonicSeq(int arr[], int n) {
	    int result = 0;
	    if (n > 0) {
	        int dp[][] = new int[2][n];
	        dp[0] = new int[n];
	        dp[1] = new int[n];
	        dp[0][0] = 1;
	        dp[1][0] = 1;
	        for(int i=1;i<n;i++){
	            int maxIncVal = Integer.MIN_VALUE;
	            int maxDecVal = Integer.MIN_VALUE;
	            for(int j=i-1;j>=0;j--){
	                int currVal = Math.max(dp[0][j], dp[1][j]);
	                if (arr[j] < arr[i] && dp[0][j] > maxIncVal) {
	                    maxIncVal = dp[0][j];
	                }
	                if (arr[j] > arr[i] && currVal > maxDecVal) {
	                    maxDecVal = currVal;
	                }
	            }
	            maxIncVal = maxIncVal == Integer.MIN_VALUE ? 0 : maxIncVal;
	            maxDecVal = maxDecVal == Integer.MIN_VALUE ? 0 : maxDecVal;
	            dp[0][i] = maxIncVal + 1;
	            dp[1][i] = maxDecVal + 1;
	        }
	        result = Math.max(dp[0][0], dp[1][0]);
	        for(int i=1;i<n;i++){
	            int currMax = Math.max(dp[0][i], dp[1][i]);
	            result = Math.max(result, currMax);
	        }
	    }
	    return result;
	}
}
