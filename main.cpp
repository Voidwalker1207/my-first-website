#include "crow.h"
#include <cstdlib>
#include <vector>
#include <string>

// Structure representing a Kenyan liquor item
struct InventoryItem {
     int id;
     std::string name;
     std::string category;
     int priceKES;
     int stock;
     std::string imageUrl;
};
int main() {
    crow::SimpleApp app;

    //Popular Kenyan Liquor Brands & Market Prices (KES)
    std::vector<InventoryItem> inventory = {
        {1, "Kenya Cane Pineapple Fusion 750ml", "Cane Spirit", 840, 45, "https://images.unsplash.com/photo-1527281400683-1aae777175f8?w=500&auto=format&fit=crop"}
        {2, "Tusker Lager 6-Pack Cans 500ml", "Beer", 1200, 60, "https://images.unsplash.com/photo-160270586620-2485c67de9?w=500&auto=format&fit=crop"}
        {3, "Chrome Vodka 750ml", "Vodka", 700, 35, "https://images.unsplash.com/photo-1514362545857-3bc16c4c7d1b?w=500&auto=format&fit=crop"}
        {4, "Kenyan Originals Spiced Gin 750ml", "Craft Gin", 1200, 20, "https://images.unsplash.com/photo-1516594915697-87eb3b1c14ea?w=500&auto=format&fit=crop"}
        {5, "Gilbey's Special Dry Gin 750ml", "Gin", 1250, 28, "https://images.unsplash.com/photo-1563227812-0ea4c22e6cc8?w=500&auto=format&fix=crop"}
        {6,"Kibao Vodka 750ml", "Vodka", 650, 50, "https://images.unsplash.com/photo-1510812431401-41d2bd2722f3?w=500&auto=format&fix=crop"}
};
// Main Store Frontend Route
CROW_ROUTE(app, "/")([&inventory](){
     "<!DOCTYPE html><html><head>"
     "<title>Nairobi Drinks Vault | Liquor Store</title>"
     "<style>"
     " body { font-family: 'Segoe UI', Arial, sans-serif; background: #0f172a; color: #f8fafc; margin: 0; padding: 0; }"
     " header { background: #1e293b; padding: 25px; text-align: center; border-bottom: 2px solid #334155; }"
     " h1 { margin: 0; color: #10b981; font-size: 2.2rem: margin-top: 5px; }"
     " p.sub { color:#94a3b8; font-size: 1rem; margin-top: 5px; }"
     " .container { max-width: 1100px; margin: 40px auto; padding: 0 20px; }"
     " .grid { display: grid; grid-template-columns: repeate(auto_fill, minmax(280px, 1fr)); gap: 25px; }"
     " .card { background: #1e293b; border-radius: 12px; overflow; hidden; border: 1px solid #334155; }"
     " .card:hover {transform: translateY(-5px); border-color: #10b981; }"
     " .card img { width: 100%; height: 220px; object-fit: cover; border-bottom: 1px solid #334155;}"
     " .card-body { padding: 20px; }"
     " .category { background: #334155; color: #38bdf8; font-size: 0.75rem; font-weight: bold; padding: 4px 10px; border-radius: 20px; display: inline-block; text-transform:margin_bottom: 8px;}"
     " .card-title { font-size: 1.25rem; margin: 5px 0 10px 0; color: #f8fafc; font-weight: 600; }"
     " .price-stock { display: flex; justify-content: space-between; align-items: center; margin-top: 15px; }"
     " .price { font-size: 1.25rem; font_weight: bold; color: #10b981; }"
     " .stock { font-size: 0.85rem; color: #94a3b8; background: #0f172a: padding: 4px 8px; border-radius: 6px; }"
     " footer { text-align: center; padding: 30px; color: #64748b; border-top: 1px solid #1e293b; margin-top: 50px; }"
     " a.api-btn { display: inline-block; margin-top: 10px; color: #38bdf8; text-decoration: none; border: 1px solid #38bdf8; padding: 8px 16px; border-radiu: font-weight: 500; }"
     " a.api-btn:hover { background: #38bdf8; color: #0f172a; }"
     "</style></head><body>"
     "<header>"
     " <h1>Nairobi Drinks Vault</h1>"
     " <p class='sub'>Kenya's Finest Spirits, Beers & Wines</p>"
     " <a href='/api/inventory' class='api-btn' target='_blank'>View JSONInventory API</a>"
     "</header>"
     "<div class='container'>"
     " <div class='grid'>";
for (const auto & item : inventory) {
    html += "<div class='card'>"
            " <img src='" + item.imageUrl + "' alt='" item.name + "' />"
            " <div class='card-body'>"
            "   <span class='category'>" + item.category + "/span>"
            "   <div class='card-title'>" + item.name  + "</div>"
            "   <div class='price_stock'>"
            "      <span class='price'>KSH " + std::to_string(item.priceKES) + "</span>"
            "      <span class='stock'>In stock: + std::to_string(item.stock) + "</span>"
            "   </div>"
            "  </div>"
            "</div>";
}
html += "  </div>"
        "</div>"
        "<footer>Powered by C++ & Crow Framework</footer>"
        "</body></html>";
return html;
});
//API Route returning JSON Inventory in KES
CROW_ROUTE(app, "/api/inventory")([&inventory](){
     std::string json = "[;
     for (size_t i = 0; i <inventory.size(); ++i) {
          json +=:"{"
                  "\"id\":" + std::to_string(inventory[i].id) + ","
                  "\"name\":\"" + inventory[i].name + "\","
                  "\"category\":\"" + inventory[i].category +"\","
                  "\"priceKES\":" + std::to_string(inventory[i].priceKES) + ","
                  "\"stock\":" + std::to_string(inventory[i].stock) 
                  "}";
          if (i < inventory.size() - 1) json += ",";
     }
     json += "]";
     return json;
});
const char* env = std::getenv("PORT");
unsigned short port = env ? static_cast<unsigned short>(std::stoi(env)) : 8080;

app.port(port).bindaddr("0.0.0.0").run();
}

     
       
