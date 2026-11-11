
import java.io.*;
import java.sql.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/Login")
public class Login extends HttpServlet {
    public void doPost(HttpServletRequest req, HttpServletResponse res)
            throws IOException {
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/studentdb", "root", "password");
            PreparedStatement ps = con.prepareStatement(
                "SELECT * FROM users WHERE name=? AND password=?");
            ps.setString(1, req.getParameter("name"));
            ps.setString(2, req.getParameter("password"));
            ResultSet rs = ps.executeQuery();
            res.getWriter().println(
                rs.next() ? "Login Successful" : "Invalid Login");
            con.close();
        } catch(Exception e) {
            res.getWriter().println(e);
        }
    }
}


// 5. MySQL

// CREATE DATABASE studentdb;
// USE studentdb;
// CREATE TABLE users (
//     name VARCHAR(50),
//     password VARCHAR(50)
// );