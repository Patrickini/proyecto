//Vertex
    #version 430 core
 
    layout (location = 0) in vec4 vPosition;
    uniform vec4 vColor;
 
    out vec4 color;
    uniform mat4 transform;
 
    void main()
    {
       
        color = vColor;
 
        gl_Position = transform * vPosition;
    }
