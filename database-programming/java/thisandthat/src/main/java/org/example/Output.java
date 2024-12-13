package org.example;

import java.sql.*;

public class Output {
    private static Connection conn;

    public static void main(String[] args) {
        String localURL = "jdbc:mysql://localhost:3306/";
        String db = "thisandthat";
        String user = "root";
        String pw = "parola";

        try {
            conn = DriverManager.getConnection(localURL + db, user, pw);
            queryArticleContent();
            conn.setAutoCommit(false);
        } catch (SQLException e) {
            System.out.println(e);
            e.printStackTrace();
        }
    }

    public static void queryArticleContent() throws SQLException {
        Statement st = conn.createStatement();
        String sqlQuery = "SELECT * FROM ARTICLE;";
        ResultSet rs = st.executeQuery(sqlQuery);

        System.out.printf("%-15s\t\t%-30s\t\t%s\n", "Article ID", "Article", "Price");
        System.out.printf("%-15s\t\t%-30s\t\t%s\n", "----------", "----------", "----------");
        while (rs.next()) {
            System.out.printf("%-15s\t\t%-30s\t\t%.2f %s\n",
                    rs.getString("article_id"),
                    rs.getString("article"),
                    Double.parseDouble(rs.getString("price")),
                    rs.getString("currency")
            );
        }

        st.close();
        rs.close();
    }
}
