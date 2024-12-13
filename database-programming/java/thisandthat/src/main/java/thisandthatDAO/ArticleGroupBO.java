package thisandthatDAO;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ArticleGroupBO {
    private Connection connection;
    private Statement stm;
    private PreparedStatement pst;

    public ArticleGroupBO() {
    }

    public List<ArticleGroup> getAllArticleGroups() throws SQLException {
        String query = "SELECT * FROM ARTICLEGROUP";
        ResultSet rs = null;
        List<ArticleGroup> ags = new ArrayList<>();

        try {
            connection = ConnectionFactory.getConnection();
            stm = connection.createStatement();
            rs = stm.executeQuery(query);

            while (rs.next()) {
                ArticleGroup ag = new ArticleGroup();
                ag.setArticleGroupId(rs.getInt("ARTICLEGROUP_ID"));
                ag.setArticleGroupName(rs.getString("ARTICLEGROUP"));
                ag.setDeleted(rs.getBoolean("DELETED"));
                ags.add(ag);
            }
        } finally {
            connection.close();
            stm.close();
            assert rs != null;
            rs.close();
        }

        return ags;
    }

    public ArticleGroup getArticleGroup(int articleGroupId) throws SQLException {
        connection = ConnectionFactory.getConnection();
        String query = "SELECT * FROM ARTICLEGROUP AS ag JOIN ARTICLE_NM_ARTICLEGROUP as jt ON ag.ARTICLEGROUP_ID = jt.ARTICLEGROUP_ID JOIN ARTICLE article ON jt.ARTICLE_ID = article.ARTICLE_ID WHERE ag.ARTICLEGROUP_ID=?";
        ResultSet rs = null;
        ArticleGroup ag;
        ag = new ArticleGroup();

        try {
            pst = connection.prepareStatement(query);
            pst.setInt(1, articleGroupId);
            rs = pst.executeQuery();
            List<Article> article = new ArrayList<Article>();
            while (rs.next()) {
                ag.setArticleGroupId(rs.getInt("ARTICLEGROUP_ID"));
                ag.setArticleGroupName(rs.getString("ARTICLEGROUP"));
                ag.setDeleted(rs.getBoolean("DELETED"));

                Article art = new Article();
                art.setArticle_Id(rs.getInt("ARTICLE_ID"));
                art.setArticleName(rs.getString("ARTICLE"));
                article.add(art);
                ag.setArticles(article);
            }

        } finally {
            connection.close();
            pst.close();
            assert rs != null;
            rs.close();
        }
        return ag;
    }


    public void addArticleGroup(ArticleGroup ag) throws SQLException {
        connection = ConnectionFactory.getConnection();
        String query = "INSERT INTO ARTICLEGROUP (ARTICLEGROUP) VALUES (?)";
        try (PreparedStatement pst = connection.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)) {
            pst.setString(1, ag.getArticleGroupName());
            int rowsAffected = pst.executeUpdate();

            if (rowsAffected == 1) {
                ResultSet generatedKeySet = pst.getGeneratedKeys();
                if (generatedKeySet.next()) {
                    int id = generatedKeySet.getInt(1);
                    ag.setArticleGroupId(id);
                }
                connection.commit();
            } else {
                connection.rollback();
                System.err.println("Failed to insert ArticleGroup " + ag.getArticleGroupName());
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {

            connection.close();
            if (pst != null) {
                pst.close();
            }
        }
    }

    public void deleteArticleGroup(ArticleGroup articleGroup) throws SQLException {
        connection = ConnectionFactory.getConnection();
        String query = "DELETE FROM ARTICLEGROUP WHERE ARTICLEGROUP_ID = ?";

        try (PreparedStatement pst = connection.prepareStatement(query)) {
            pst.setInt(1, articleGroup.getArticleGroupId());
            int rowsAffected = pst.executeUpdate();
            if (rowsAffected == 1) {
                connection.commit();
                System.out.println("Deleting ArticleGroup " + articleGroup.getArticleGroupName() + " with ID: " + articleGroup.getArticleGroupId());
            } else {
                connection.rollback();
                System.err.println("Failed to delete ArticleGroup " + articleGroup.getArticleGroupName() + " with ID: " + articleGroup.getArticleGroupId());
            }
        } catch (SQLException e) {
            connection.rollback();
            throw e;
        } finally {
            connection.close();
        }
    }
}
