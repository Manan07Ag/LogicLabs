#include <GLFW/glfw3.h>
#include <cstdlib> 

int windowWidth = 500;
int windowHeight = 500;

struct Color {
    float r, g, b;
};

struct Cell {
    int x, y;
    Color color;

    void randomizeColor() {
        color.r = rand() % 256 / 255.0f;
        color.g = rand() % 256 / 255.0f;
        color.b = rand() % 256 / 255.0f;
    }
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, windowWidth, windowHeight);
}

void drawGrid() {
    int cellSize = 50;  // Desired size of each cell
    int numCellsX = windowWidth / cellSize;
    int numCellsY = windowHeight / cellSize;

    float normalizedCellWidth = 2.0f / numCellsX; // Normalized width of each cell in OpenGL coords
    float normalizedCellHeight = 2.0f / numCellsY; // Normalized height of each cell in OpenGL coords

    for (int x = 0; x < numCellsX; ++x) {
        for (int y = 0; y < numCellsY; ++y) {
            Cell cell;
            cell.x = x;
            cell.y = y;
            cell.randomizeColor();

            glColor3f(cell.color.r, cell.color.g, cell.color.b);
            glBegin(GL_QUADS);
                glVertex2f(x * normalizedCellWidth - 1.0f, y * normalizedCellHeight - 1.0f);
                glVertex2f((x + 1) * normalizedCellWidth - 1.0f, y * normalizedCellHeight - 1.0f);
                glVertex2f((x + 1) * normalizedCellWidth - 1.0f, (y + 1) * normalizedCellHeight - 1.0f);
                glVertex2f(x * normalizedCellWidth - 1.0f, (y + 1) * normalizedCellHeight - 1.0f);
            glEnd();
        }
    }
}


int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Colored Grid", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawGrid();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
