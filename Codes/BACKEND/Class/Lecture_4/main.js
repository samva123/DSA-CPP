const fs =  require("fs");


fs.writeFile("hello.txt", "Hello, World!", (err) => {
  if (err) {
    console.error("Error writing file:", err);
  } else {
    console.log("File written successfully!");
  }
});


fs.writeFileSync("hello.txt", "Hello, World Sync!");



fs.readFile("hello.txt", "utf8", (err, data) => {
  if (err) {
    console.error("Error reading file:", err);
  } else {
    console.log("File content:", data);
  }
});

const data = fs.readFileSync("hello.txt", "utf8");
console.log("File content (sync):", data);


