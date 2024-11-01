package controller;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import java.io.IOException;
import javax.json.Json;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author isharaLakshitha
 */
//http://localhost:8080/ESP_Server/Test
@WebServlet(name = "Test", urlPatterns = {"/Test"})
public class Test extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String name = request.getParameter("name");
        
        Gson gson = new Gson();
        JsonObject jsonobject = new JsonObject();
        jsonobject.addProperty("x","10");
        jsonobject.addProperty("y","20");

        response.setContentType("application/json");
        response.getWriter().write(gson.toJson(jsonobject));
    }

}
