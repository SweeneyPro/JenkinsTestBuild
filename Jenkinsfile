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
        bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\JenkinsTestBuild\\CompileBatch.bat'
      }
    }
    stage('Run') {
      steps {
        bat 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\JenkinsTestBuild\\RunBatch.bat'
        archiveArtifacts 'JenkinsTestBuild/JenkinsTestBuild/Jsontest.json'
      }
    }
    stage('TestResults') {
      steps {
        livingDocs(numbered: true, sectAnchors: true)
      }
    }
  }
}