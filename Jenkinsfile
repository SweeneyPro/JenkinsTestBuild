pipeline {
  agent any
  stages {
    stage('Fetch Repo') {
      steps {
        git 'https://github.com/SweeneyPro/JenkinsTestBuild.git'
      }
    }
    stage('Compile') {
      steps {
        bat 'call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvarsx86_amd64.bat C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\JenkinsTestBuild\\'
      }
    }
    stage('Message') {
      steps {
        echo 'Done'
      }
    }
  }
}