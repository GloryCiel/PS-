import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int test = Integer.parseInt(br.readLine());
        while (test-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int r1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());

            int sqd = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

            int rs = (r1 + r2) * (r1 + r2);
            int rd = (r1 - r2) * (r1 - r2);

            if (x1 == x2 && y1 == y2 && r1 == r2) {
                sb.append(-1);
            } else if (sqd > rs) {
                sb.append(0);
            } else if (sqd == rs) {
                sb.append(1);
            } else if (rd < sqd) {
                sb.append(2);
            } else if (sqd == rd) {
                sb.append(1);
            } else {
                sb.append(0);
            }

            sb.append('\n');
        }

        System.out.print(sb);
    }
}