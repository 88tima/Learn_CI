pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh "docker build -t chess-moves .
                sh "docker run -it chess-moves"
            }
        }
    }
}
