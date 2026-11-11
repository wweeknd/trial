
import java.io.*;
import java.sql.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet("/Register")
public class Register extends HttpServlet {
    public void doPost(HttpServletRequest req, HttpServletResponse res)
            throws IOException {
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/studentdb", "root", "password");
            PreparedStatement ps = con.prepareStatement(
                "INSERT INTO users VALUES (?,?)");
            ps.setString(1, req.getParameter("name"));
            ps.setString(2, req.getParameter("password"));
            ps.executeUpdate();
            res.getWriter().println("Registration Successful");
            con.close();
        } catch(Exception e) {
            res.getWriter().println(e);
        }
    }
}
