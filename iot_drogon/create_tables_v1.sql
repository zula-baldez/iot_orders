CREATE TABLE IF NOT EXISTS order_list
(
    id  INT AUTO_INCREMENT PRIMARY KEY,
    uid BIGINT
);

CREATE TABLE IF NOT EXISTS order_item
(
    id          INT PRIMARY KEY,
    price       DOUBLE,
    order_id    INT,
    is_approved BOOLEAN, #TODO PRODUCT ID
    FOREIGN KEY (order_id) REFERENCES order_list (id)
);
