package thisandthatDAO;

import com.mysql.cj.x.protobuf.MysqlxPrepare;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ArticleBO implements ArticleDAO {
    private Connection connection;
    private Statement stm;
    private PreparedStatement pst;

    public ArticleBO() {
    }

    public Article getArticle(int article_Id) throws SQLException {
        String query = "SELECT * FROM ARTICLE WHERE ARTICLE_ID = ?";
        ResultSet rs = null;
        Article article = new Article();
        try {
            connection = ConnectionFactory.getConnection();
            pst = connection.prepareStatement(query);
            pst.setInt(1, article_Id);
            rs = pst.executeQuery();
            while (rs.next()) {
                article.setArticle_Id(rs.getInt("ARTICLE_ID"));
                article.setArticleName(rs.getString("ARTICLE"));
                article.setPrice(rs.getInt("PRICE"));
                article.setCurrency(rs.getString("CURRENCY"));
                article.setDeleted(rs.getBoolean("DELETED"));
            }
        } finally {
            assert rs != null;
            rs.close();
            pst.close();
            connection.close();
        }
        return article;

    }

    public List<Article> getAllArticle() throws SQLException {
        String query = "SELECT * FROM ARTICLE;";
        List<Article> articles = new ArrayList<Article>();
        ResultSet rs = null;
        try {
            connection = ConnectionFactory.getConnection();
            pst = connection.prepareStatement(query);
            rs = pst.executeQuery();
            while (rs.next()) {
                Article art = new Article();
                art.setArticle_Id(rs.getInt("ARTICLE_ID"));
                art.setArticleName(rs.getString("ARTICLE"));
                art.setCurrency(rs.getString("CURRENCY"));
                art.setPrice(rs.getInt("PRICE"));
                art.setDeleted(rs.getBoolean("DELETED"));
                articles.add(art);
            }
        } finally {
            pst.close();
            connection.close();
        }
        return articles;
    }

    public void updateArticle(Article article) throws SQLException {
    }

    public void deleteArticle(Article article) throws SQLException {
        connection = ConnectionFactory.getConnection();
        String query = "DELETE FROM ARTICLE_NM_ARTICLEGROUP WHERE ARTICLE_ID = ?";
        String query2 = "DELETE FROM ARTICLE WHERE ARTICLE_ID = ?";

        try (PreparedStatement pst = connection.prepareStatement(query); PreparedStatement pst2 = connection.prepareStatement(query2)) {
            pst.setInt(1, article.getArticle_Id());
            pst2.setInt(1, article.getArticle_Id());
            int rowsAffected = pst.executeUpdate();
            int rowsAffected2 = pst2.executeUpdate();

            if (rowsAffected == 1 && rowsAffected2 == 1) {
                connection.commit();
                System.out.println("Deleting article " + article.getArticleName() + " with ID: " + article.getArticle_Id());
            } else {
                connection.rollback();
                System.out.println("Encountered an error while trying to delete article \"" + article.getArticleName() + "\" with ID: " + article.getArticle_Id());
            }
        } catch (SQLException e) {
            connection.rollback();
            e.printStackTrace();
        } finally {
            connection.close();
        }
    }

    public List<ArticleGroup> getArticleGroups(int article_Id) throws SQLException {
        connection = ConnectionFactory.getConnection();
        List<ArticleGroup> ag;
        String query = "SELECT * FROM ARTICLE a " +
                "JOIN ARTICLE_NM_ARTICLEGROUP AS jt ON a.ARTICLE_ID = jt.ARTICLE_ID " +
                "JOIN ARTICLEGROUP AS ag ON jt.ARTICLEGROUP_ID = ag.ARTICLEGROUP_ID " +
                "WHERE a.ARTICLE_ID = ?";
        try (PreparedStatement pst = connection.prepareStatement(query)) {
            pst.setInt(1, article_Id);
            ResultSet rs = pst.executeQuery();
            while (rs.next()) {
                // continue implementation
            }
  } finally {
            connection.close();
        }
    }


    public void createArticle(Article article) throws SQLException {
    }

    @Override
    public void addArticleGroup(Article article, ArticleGroup articleGroup) throws SQLException {
    }

    @Override
    public void removeArticleGroup(Article article, ArticleGroup articleGroup) throws SQLException {
    }
}
