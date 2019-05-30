package _ÑùÀıÉú³É;

public class TestSamples {
	public static int[] get1Darr(int m, int min, int max) {
		int[] arr = new int[m];
		for (int i = 0; i < m; i++) {
			arr[i] = (int) (Math.random() * (max - min) + min);
		}
		return arr;
	}

	public static int[][] get2Darr(int m, int n, int min, int max) {
		int[][] arr = new int[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = (int) (Math.random() * (max - min) + min);
			}
		}
		return arr;
	}

	public static void print2Darr(int[][] arr) {
		System.out.print('[');
		for (int i = 0; i < arr.length; i++) {
			System.out.print('[');
			for (int j = 0; j < arr[0].length; j++) {
				if (j == arr[0].length - 1)
					System.out.print(arr[i][j]);
				else
					System.out.print(arr[i][j] + ",");
			}
			System.out.print(']');
			if (i != arr.length - 1)
				System.out.print(',');
		}
		System.out.print(']');
	}

	public static void print1Darr(int[] arr) {
		System.out.print('[');
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]);
			if (i != arr.length - 1)
				System.out.print(',');
		}
		System.out.print(']');
	}

	public static void generator1DSample(int times, int size, int min, int max) {
		for (int i = 0; i < times; i++) {
			print1Darr(get1Darr(size, min, max));
			System.out.println();
		}
	}

	public static void generator2DSample(int times, int row, int col, int min, int max) {
		for (int i = 0; i < times; i++) {
			print2Darr(get2Darr(row, col, min, max));
			System.out.println();
		}
	}

	public static void main(String[] args) {
		generator1DSample(4, 10, 5, 10);
		generator2DSample(4, 4, 6, 7, 20);
	}
}
