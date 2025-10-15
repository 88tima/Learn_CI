pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh "docker build -t chess-moves ."
                sh "docker run -t chess-moves"
            }
        }
    }
}
