pipeline {
    agent any
    environment {
        DOCKER_USERNAME = "88tima"
        DOCKER_IMAGE_NAME = "chess"
        DOCKER_IMAGE = "${DOCKER_USERNAME}/${DOCKER_IMAGE_NAME}"
    }
    stages {
        stage('Build') {
            steps {
                sh "docker build -t ${DOCKER_IMAGE_NAME} ."
            }
        }
        stage('Tag Image') {
            steps {
                sh "docker tag ${DOCKER_IMAGE_NAME} ${DOCKER_IMAGE}"
            }
        }
        stage('Push Image to Docker Hub') {
            steps {
                withCredentials([usernamePassword(
                    credentialsId: 'docker-hub-creds',
                    usernameVariable: 'DOCKER_USER',
                    passwordVariable: 'DOCKER_TOKEN'
                )]) {
                    sh '''
                        echo "$DOCKER_TOKEN" | docker login -u "$DOCKER_USER" --password-stdin
                        docker push $DOCKER_IMAGE
                    '''
                }
            }
        }
    }
    post {
        always {
            sh 'docker logout'
        }
    }
}

